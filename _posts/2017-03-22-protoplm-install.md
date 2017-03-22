---
layout: post
published: true
title: ProtoPLM_Install
subtitle: Recipe to install ProtoPLM on Ubuntu 16.04
date: '2017-03-22'
image: >-
  https://cloud.githubusercontent.com/assets/12775748/24198689/35818e8c-0f4a-11e7-999e-3b5cf82e15ff.png
tags: software
---
## 개요
* ProtoPLM을 설치하는 순서를 기술해 본다.
* 중소기업 또는 개발팀 정도 단위에서 개발 결과물을 생산이관시켜줄 때 이걸 사용하면 생산성을 크게 높일 수 있다고 생각된다.
* PLM 하면 보통 도입비용만 수억원~수십억원짜리 대형 프로젝트 아니냐 하는 선입견을 버리기만 하면 된다.


## Environment
* OS : Ubuntu 16.04
  - 원래 ProtoPLM-1.7은 Ubuntu 14.04에서만 테스트했다고 되어 있다.
  - 그러나 16.04에서도 설치에 성공했다.

* Network
  - 사용자 로그인 부분에서 SMTP 이메일 보내기, SSL 인증 따위가 적용되도록 설계되어 있다.
  - 따라서 Port는 웹서비스용 80, SMTP용 25 또는 465 등을 열어주어야 한다.
  - 외부 인터넷에 무방비로 노출되는 것 보다는, 최소한 공유기 등의 아래에서 방화벽으로 보호해 주는 환경으로 하는 것이 안전하겠다.


## Download
* https://protoplm.com/download.html
  - 여기서 라디오버튼 체크해 주고 다운로드 받으면 된다.
  - 일단 자신의 홈디렉토리(`~`)에 받는다고 하자.


## Install
* Extract

```bash
tar -xvzf ~/protoplm-1.7-src.tar.gz
mv dist/ protoplm-1.7-src/
```

* apt-get

```bash
sudo apt-get update
sudo apt-get install ntp mongodb apache2 libapache2-mod-perl2 libapreq2-3 libapache2-request-perl libdigest-sha-perl libnet-sslglue-perl libspreadsheet-writeexcel-perl libspreadsheet-read-perl expat libexpat1-dev libxml-parser-perl build-essential cpanminus libxml2-dev zlib1g-dev
```

* cpan
  - 동봉된 설명서에는 CGI를 설치하라는 부분이 빠져 있으므로 마지막에 잊지 말고 설치해 주자.

```bash
sudo cpanm Spreadsheet::ParseXLSX
sudo cpanm Spreadsheet::Read
sudo cpanm JSON
sudo cpanm Crypt::Eksblowfish::Bcrypt 
sudo cpanm Amazon::S3
sudo cpanm Data::GUID
sudo cpanm File::Temp
sudo cpanm DateTime::Format::ISO8601
sudo cpanm XML::Simple
sudo cpanm Net::DNS
sudo cpanm MongoDB
sudo cpanm CGI
```

* Symbolic Link
  - 슈퍼유저 권한으로 통째로 설치 위치에 카피해 넣는 것 보다는, 아래와 같이 자신의 홈 디렉토리에 소스를 그대로 두고 심볼릭 링크를 걸어주는 쪽이 관리도 용이하고 좀 더 우아한 것 같다.

```bash
sudo mkdir /usr/local/lib/site_perl
sudo ln -s ~/protoplm-1.7-src/Plm /usr/local/lib/site_perl/Plm

sudo mv /var/www/html/index.html /var/www/html/index.html.old
sudo ln -s ~/protoplm-1.7-src/html/index.html /var/www/html/index.html
sudo ln -s ~/protoplm-1.7-src/html/st /var/www/html/st
```


* Setting `ServerSetup.pm`
  - ProtoPLM의 기본 설정을 한다.

```bash
sudo nano /usr/local/lib/site_perl/Plm/ServerSetup.pm
```

아래의 내용을 참고하자.

```perl
...
$HashKey                = '0123456789abcdef0123456789abcdef';
...
$SuperUserIp            = '127.0.0.1';
...
$SuperUserHash          = Hash('슈퍼유저비번');
...
$SuperUserEmail         = '슈퍼유저이메일주소';
...
$ServerUrl              = 'http://127.0.0.1';
...
$CookiesAreSecure       = false;
...
$MongoHosts             = 'mongodb://localhost';
...
# If your SMTP server uses STARTTLS authentication, then just fill in the
# server, username, and password.
sub SmtpConnectAndAuthenticate {
    my $SMTP_USER   = '이메일주소';
    my $SMTP_PASS   = '이메일비밀번호';
    my $SMTP_SERVER = 'smtp서버주소';

    my $smtp = Net::SMTP->new(
        $SMTP_SERVER,
		Port => 25,
		Timeout => 120,
        SSL => 0,
        SSL_ca_path => '/etc/ssl/certs',
        Debug => 0);

    $smtp->auth($SMTP_USER, $SMTP_PASS) or
                         print STDERR "smtp auth error: " . $smtp->message();
    return $smtp;
}
...
```

> 특히 `$CookiesAreSecure=false`는 꼭 확인하자.
> SMTP로 이메일 발송하도록 하는 부분도 중요하다.  위 예제에서는 SSL 인증을 안하는 SMTP 서버이기 때문에 `SSL => 0`으로 되어 있다.  SSL 인증을 해야 할 경우에는 `1`로 고쳐주자.  다만 나는 이게 제대로 작동하는지 확실히 검증하지는 아직 못했다.
> `Port` 및 `Timeout` 부분도 원래 소스에 없던 건데 구글링을 통해 참고해서 추가해 넣었다.


* Setting `apache2.conf`
  - 아파치 서버의 기본 설정을 한다.

```bash
sudo nano /etc/apache2/apache2.conf
```

아래의 내용을 맨 마지막에 그대로 추가해 주면 된다. :

```
...
#
# ProtoPLM
#
<Location /repo>
  SetHandler perl-script
  PerlResponseHandler Plm::Main
</Location>

# limit CPU usage in seconds
PerlSetEnv PERL_RLIMIT_CPU 10:15
# limit DATA segment in MB
PerlSetEnv PERL_RLIMIT_DATA 120:140
PerlChildInitHandler Apache::Resource

# Very important; by loading modules before forking, we make most of
# the memory a one-time cost, not a cost per child
PerlPostConfigRequire /usr/local/lib/site_perl/Plm/Main.pm

StartServers 5
MinSpareServers 5
MaxSpareServers 10
MaxRequestWorkers 15
MaxConnectionsPerChild 10

ServerName 127.0.0.1
```


* Setting `000-default.conf`
  - 아파치의 버추얼 호스트 설정이다.
  - 아파치 서버에 대한 이해도가 있다면, 이것 외에 다른 부분들도 상세하게 셋팅해 줄 수 있을 것이다.

```bash
sudo nano /etc/apache2/sites-available/000-default.conf
```

다음 내용을 참고하자. :

```
<VirtualHost *:80>
...
	ServerName 127.0.0.1
	DocumentRoot /var/www/html
...
</VirtualHost>
```


* Setting `default-ssl.conf`
  - 본 예제에서는 SSL 인증을 안하기 때문에 사실 불필요한 부분이다.
  - 하지만 나중에 혹시 모르니까 일단 써 둔다.

```bash
sudo ln -s /etc/apache2/sites-available/default-ssl.conf /etc/apache2/sites-enabled/default-ssl.conf
sudo pluma /etc/apache2/sites-available/default-ssl.conf
```

다음 내용을 참고하자. :

```
<IfModule mod_ssl.c>
	<VirtualHost _default_:443>
		...
		DocumentRoot /var/www/html
		SSLEngine on
		SSLCertificateFile /etc/ssl/certs/ssl-cert.crt
		SSLCertificateKeyFile /etc/ssl/certs/ssl-key.key
		SSLCertificateChainFile /etc/ssl/certs/ssl-cert-chain.crt
		...
	</VirtualHost>
</IfModule>
```


* First execution (최초 실행)

```bash
    sudo a2enmod ssl
    sudo a2dismod mpm_event
    sudo a2enmod mpm_prefork
    sudo service apache2 restart
    sudo /etc/init.d/mongodb restart
    perl /usr/local/lib/site_perl/Plm/nonweb.pl cleanup
```


* Connect in web browser & Check (웹브라우저로 들어가서 확인)

```
http://127.0.0.1
```


* Auto Cleanup (클린업 동작을 다음부터 자동으로 해 주도록 하는 것)

```bash
perl /usr/local/lib/site_perl/Plm/nonweb.pl otsd
```


* Check sites in web browser (상태 확인)

```
http://127.0.0.1/repo/log
http://127.0.0.1/repo/health
```


## 끝!
* 이제까지 여러가지 오픈소스 PLM을 오랫동안 찾아 헤메었는데, ProtoPLM이 제일 괜챦은 것 같다.
* 기타 다른 것으로는 OpenPLM, DocDoku 같은 것들이 있었는데, 이것들은 파이썬 쟝고 및 Java 기반이라 너무 심하게 복잡했다.  사실 따지고 보면 이 작고 가벼운 ProtoPLM보다 엄청나게 좋고 뭐 그렇지도 않다.
* 그 외에 인상적인 것으로는 [PLMAPI](https://plmapi.wordpress.com/)라는게 있었다.  PLM 기능을 할 수 있도록 자유롭게 웹앱을 만들수 있도록 준비된 API 형태의 코드인데...  나는 개발자가 아니고 사용자에 가까울 뿐만 아니라, 웹앱을 개발할 만큼 한가한 상황도 아닌지라 흥미는 땡기지만 활용을 포기했다.  뭐 그래도 이게 정말 쓸만 하다면, 기업마다 커스텀으로 빠르게 간이 PLM을 개발할 때 프레임워크 처럼 사용할 수도 있겠구나 싶었다.






