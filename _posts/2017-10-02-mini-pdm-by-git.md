---
layout: post
published: true
title: Mini_PDM_by_Git
subtitle: 'Git을 PDM으로 지금 당장 구축, 활용할 수 있는 방법'
date: '2017-10-02'
bigimg: /img/bigimg39.jpg
image: >-
  https://user-images.githubusercontent.com/12775748/31080618-2c2c7f1e-a7c4-11e7-8c16-38dccaf76cdd.png
tags: software
---

## 개요
* 인터넷을 뒤져보면 대략 2010~2012년경부터 Git을 [PDM](https://ko.wikipedia.org/wiki/%EC%A0%9C%ED%92%88_%EB%8D%B0%EC%9D%B4%ED%84%B0_%EA%B4%80%EB%A6%AC)의 기반으로 사용 가능한가 하는 논의가 시작된 것 같다.  여기에 대해서 찬반 의견이 갈렸는데, 대략 다음과 같다.

|의견|근거|
|----|----|
|찬성론|완벽하게 분산화된 환경, 유연한 브랜치 확장 등 엄청난 잠재력을 가지고 있다.  기존의 PDM에 대한 고정관념만 버리면 된다.|
|반대론|코딩하는 애들이나 쓰는 건데 용량 많은 바이너리 파일 위주의 CAD 시스템에는 별로 적합하지 않다.  게다가 분산형이다 보니 Lock 같은 것도 원리적으로 불가능하지 않느냐?  꿈 깨라.|

* 이후 몇 년 더 지나면서, 반대론의 근거가 된 약점들이 보완될 수 있는 솔루션들이 나타나고 발달해오고 있다.  대략 가늠하기에, 현재 시점에서는 어느정도 충분히 실무에 사용할 만한 수준이 되었다고 생각된다.
* 제일 큰 것은, [Git LFS](https://git-lfs.github.com/)의 출현이다.  바이너리 파일을 별도로 취급해서 클라이언트 쪽의 부담을 줄여주는 것이다.  LFS와 비슷한 것으로 오픈소스 [git-annex](https://git-annex.branchable.com/) 및 [MS GVFS](https://github.com/Microsoft/GVFS) 같은 것들도 있는데, 여러 측면에서 LFS가 가장 적합하다.
* 게다가 LFS 초기에는 설치 및 운용이 상당히 까다롭다고 할 수 있었는데, 현재는 상당히 간단하게 사용 할 수 있도록 편리하게 여러 툴들에 녹아들어가고 있다.
* 개인적으로 검토해 본 결과, 다음과 같은 솔루션을 이용해서 구축하면 가장 저렴하고 안정적이면서 실무에 쓸만한 PDM이 구축된다고 생각된다.  물론 아직은 2% 부족한 부분도 있다.  본문에서 자세히 다루도록 하겠다.

|구분|솔루션|용도|개발사|특징|
|----|------|----|-----|----|
|서버 하드웨어|Raspberry Pi 3 B|간이 서버 컴퓨터|영국 라즈베리파이 재단|저전력,저렴,초소형,간단|
|서버 OS|Rasbian|서버 OS|영국 라즈베리파이 재단|안정적인 생태계로 지속적인 업데이트 가능|
|서버 APP|Gitea|웹서비스 서버|오픈소스 커뮤니티|매우 가볍고 간편하면서도 강력함|
|클라이언트|Git Windows|클라이언트단 Git 코어|오픈소스 커뮤니티|윈도우 환경에서 간단하게 Git 설치|
|클라이언트|SourceTree|클라이언트단 GUI|Atlassian사|Git에 관한 숙련도가 낮아도 사용가능|

* 사용하기 쉬운 클라이언트 GUI 앱으로, [Tortoise Git](https://tortoisegit.org/)이 많이 추천되지만, 여기서는 적합하지 않은 것 같다.  이유는 LFS를 아직 지원하지 않는다.  이외에 여러가지 다른 것들도 많지만, 대체로 [SourceTree](https://www.sourcetreeapp.com/)를 가장 우위에 두는 것 같다.  물론 오픈소스 무료 소프트웨어 중에서다.  (상용 프로그램 중에는 그래픽 디자이너를 위한 전용 클라이언트 앱 같은 것도 있는 것 같다.)


## 벤치마킹

### Solidworks용으로 git을 PDM으로 운용해 본 사례
* https://plus.google.com/u/0/+BenFrantzDale/posts/5VnStcG1nQn
* Ben FrantzDale 이라는 사람인데, 2012년도에 Git으로 운용을 시도해 본 것 같다.  현재도 사용중인지는 모른다.
* 이 사례에서는 LFS가 나타나기 전이기 때문에, 그냥 Native Git으로 운용을 했었다.  걱정했던 파일 용량 증가도 그렇게 기하급수적이지는 않았던 것 같다.  그럼에도 불구하고 퍼포먼스를 충분히 뽑아내지는 못했을 수 있다.

### Peer to Peer PDM
* http://www.proetoolbox.co.uk/6_Peer_To_Peer_PDM/P2PIdea.html
* Chris Lewis라는 개인 개발자가, Creo 용으로 Git 기반의 PDM 시스템을 개발했던 사례다.
* 특징은 Serverless 다시말해 모든 사용자가 서버 겸 클라이언트로 P2P 모델을 가지도록 한 것이다.
* 단점은 Creo GUI 안으로 무리하게 넣다 보니, 설치가 엄청나게 까다롭고 또 내 경우엔 설치에 결국 실패했다.  MS IE 기반의 Web.Link를 사용한 것은 정말 실수다.
* 또 Serverless 모델이다 보니, 모든 사용자는 Git 서버와 클라이언트 데이타를 동시에 가져야 하므로 데이타 용량은 2배로 더 커진다.  자원 낭비 측면이 좀 있다.  규모가 커지면 분명 문제가 될 수 있다.

### 기타 SVN 기반 사례들
* Git 말고 좀 더 전통적인 SVN으로 구축한 사례들은 많다.
* SVN 서버를 구축해 주고, 클라이언트로 적당히 쓰면 별 차이가 없을 것이지만, Git 보다 퍼포먼스나 확장성이 더 떨어질 것으로 생각한다.
* GrabCAD 서비스도 SVN 기반인데, 재미있는 것은 GrabCAD에서는 Git을 PDM으로 사용하는 것을 '실수'라고 주장한다는 것이다.  물론 그럴 수도 있다.  하지만 모든 경우에 그렇다고 주장하는 건 아닐 것이다.  GrabCAD Workbench는 브랜치도 지원하지 않기 때문에 비선형적 업데이트가 불가능하다.  즉 이 서비스도 완벽하지는 않다.




## 라즈베리파이 서버 구축
* 물론 퍼블릭 서비스를 사용해도 아무 문제가 없다.  그러나 여기서는 프로페셔널한 소규모 팀에서 사용한다고 가정을 하고, 사무실 안이나 집에 설치할 수 있는 작은 Vault 서버 역할을 하도록 구축해 주는 것을 가정한다.  물론 Git 서버 기능을 추가할 수 있는 NAS 제품이나 전용 x86 서버를 사용해도 무방하다.  다만 여기서는 최대한 저렴하게 맞춰보는 것이다.

* 라즈베리파이, 전원어댑터, SD메모리 해서 대략 7만원 안팎이면 구입할 수 있을 것이다.  처음에 이대로 사용하다가, 용량이 필요하면 HDD를 추가해서 마운트시켜주면 된다.

### SD메모리에 OS 심어넣기
* ISO 이미지는 노말하게 [이곳](https://www.raspberrypi.org/downloads/raspbian/)에서 라즈비안 스트레치 라이트(Raspbian Stretch Lite) 버전을 받는다.
* 이미지 라이팅은 [Etcher](https://etcher.io/)를 이용하는 것이 가장 간단한 것 같다.

### 최초 부팅
* OS를 심어넣은 SD메모리를 라즈베리파이에 넣고 부팅 실시.
* 모니터화면,키보드 정도는 꽂아주자.
* 최초 로그인은 ID=pi, PW=raspberry 로 한다.  보안상 필요하다면 아이디를 새로 파고, 비번도 바꾸자.

### 설정
* 라즈비안에 기본적으로 있는 유틸리티가 좋다.  알아서 잘 설정하면 된다.

```bash
sudo raspi-config
```

### 업데이트
* 최초 업데이트

```bash
sudo apt update
sudo apt upgrade
sudo apt-get dist-upgrade
sudo reboot now
```

### 시스템 체크
* 리눅스 배포판, 커널 버전 확인

```bash
grep . /etc/issue*
uname -r
```

* 온도 체크

```bash
vcgencmd measure_temp
```

* 메모리 사용량 체크

```bash
free -m
cat /proc/meminfo
```

### 네트워크 설정
* 현재의 네트워크 상태 확인

```bash
ifconfig
```

* 공유기를 통해 인터넷과 연결되어 있다면, 공유기와 잘 쇼부를 봐서(?) 적절하게 셋팅해 준다.



## 서버에 Gitea 설치 및 서비스 시작

* 오리지널 git 서버, 또는 Atlassian Stash, Gitlab 같은 것들은 설치하고 셋팅하는게 너무 고통스럽다.  이런 것들 말고, 아주 간단하게 서버 설치가 되는 것을 사용하도록 하자.  그게 바로 Gogs 또는 거기서 포크된 Gitea이다.

* Gogs 보다 Gitea 쪽이 업데이트가 더 활발하고, 개발자 및 사용자 층이 더 두텁다.  Gogs 말고 Gitea 쪽을 쓰는게 낫다는 생각이다.

* Gitea는 이미 LFS 서버 기능도 포함되어 제공된다.  간단한 설정만 해주면 끝난다.

* Go 언어로 만든 어플리케이션의 장점을 크게 누릴 수 있다.  예컨데, 하나의 단일 실행파일로 빌드된 것을 그냥 다운로드 받아 덮어써 주기만 해도 업데이트 되는 식이다.

* 설치 방법은 여기에 별도 정리 : https://dymaxionkim.github.io/beautiful-jekyll/2017-10-03-gitea/



## 클라이언트에 Git 설치

* SourceTree는 Git Core를 별도로 설치해서 그걸 기반으로 동작하도록 할 수도 있고, 또 SourceTree 자체 내장된 Git Core를 사용하도록 설정할 수도 있도록 선택 가능한 것 같다.  일단 나는 별도 설치로만 해 봤고, 또 일반적으로 별도 설치가 권장되므로 여기서도 그렇게 하는게 낫겠다.

* 윈도우 환경에서 사용할 수 있는 Git core로 가장 대표성이 있는 스탠다드 버전이라고 할 수 있는 [Git-scm](https://git-scm.com/downloads) 또는 [Git for Windows](https://git-for-windows.github.io/)를 설치해 준다.  아마 둘 다 같은 것으로 봐도 되지 않나 싶다.


## 클라이언트에 SourceTree 설치

* SourceTree에 LFS File Locking 기능을 추가할 가능성은 아직 높지 않다. ([참고](https://community.atlassian.com/t5/Questions/Now-that-GIT-LFS-supports-File-locking-will-Source-Tree-support/qaq-p/599215))  LFS File Locking 기능이 적용된 다른 오픈소스 GUI 클라이언트 툴도 아직 보이지 않는다.  아직 이 기능은 실험적인 성격이 강하기 때문으로 생각된다.  시간이 좀 더 지나면 아마 충분히 성숙해서 일반화되지 않을까 한다.

* 하지만 SourceTree 자체적으로 LFS 기능을 가지고 있기 때문에, 별도로 LFS 클라이언트를 설치할 필요가 없다.  이것은 큰 장점이다.

* 다운로드는 [여기](https://www.sourcetreeapp.com/download-archives)서 적절한 것으로 골라서 받아 설치한다.




## 저장소 설정

* 새로운 저장소를 만든 후, 미리 PDM 용으로 작성해 둔 `.gitattribute` 파일과 `.gitignore` 파일을 해당 저장소에 던져넣어 사용해야 한다.  그것 말고는 딱히 취해줄 조치는 없다.

* `.gitattribute` 파일 예제

```
### Images
#*.jpg filter=lfs diff=lfs merge=lfs -text lockable
#*.png filter=lfs diff=lfs merge=lfs -text lockable
#*.gif filter=lfs diff=lfs merge=lfs -text lockable
*.bmp filter=lfs diff=lfs merge=lfs -text lockable
*.tiff filter=lfs diff=lfs merge=lfs -text lockable
*.svg filter=lfs diff=lfs merge=lfs -text lockable
*.ai filter=lfs diff=lfs merge=lfs -text lockable
*.psd filter=lfs diff=lfs merge=lfs -text lockable

### pdf
*.pdf filter=lfs diff=lfs merge=lfs -text lockable

### Audio, Video
*.mp3 filter=lfs diff=lfs merge=lfs -text lockable
*.wav filter=lfs diff=lfs merge=lfs -text lockable
*.ogg filter=lfs diff=lfs merge=lfs -text lockable
*.mp4 filter=lfs diff=lfs merge=lfs -text lockable
*.mov filter=lfs diff=lfs merge=lfs -text lockable
*.avi filter=lfs diff=lfs merge=lfs -text lockable

### Compressed files
*.zip filter=lfs diff=lfs merge=lfs -text lockable
*.gz filter=lfs diff=lfs merge=lfs -text lockable
 
### MS Office
*.ppt filter=lfs diff=lfs merge=lfs -text lockable
*.pptx filter=lfs diff=lfs merge=lfs -text lockable
*.doc filter=lfs diff=lfs merge=lfs -text lockable
*.docx filter=lfs diff=lfs merge=lfs -text lockable
*.xls filter=lfs diff=lfs merge=lfs -text lockable
*.xlsx filter=lfs diff=lfs merge=lfs -text lockable
 
### Hancom Office
*.hwp filter=lfs diff=lfs merge=lfs -text lockable
 
### Libre Office
*.odt filter=lfs diff=lfs merge=lfs -text lockable
 
### AutoCAD
*.dxf filter=lfs diff=lfs merge=lfs -text lockable
*.dwg filter=lfs diff=lfs merge=lfs -text lockable
 
### PADS
*.pcb filter=lfs diff=lfs merge=lfs -text lockable
*.dsn filter=lfs diff=lfs merge=lfs -text lockable
*.pho filter=lfs diff=lfs merge=lfs -text lockable
*.rep filter=lfs diff=lfs merge=lfs -text lockable
*.gbr filter=lfs diff=lfs merge=lfs -text lockable
 
### FreeCAD
*.fcstd filter=lfs diff=lfs merge=lfs -text lockable

### Solidworks
*.sldprt filter=lfs diff=lfs merge=lfs -text lockable
*.sldasm filter=lfs diff=lfs merge=lfs -text lockable

### Rhino
*.3dm filter=lfs diff=lfs merge=lfs -text lockable

### CATIA V5
*.CATPart filter=lfs diff=lfs merge=lfs -text lockable
*.CATProduct filter=lfs diff=lfs merge=lfs -text lockable

### PTC CREO
*.asm filter=lfs diff=lfs merge=lfs -text lockable
*.prt filter=lfs diff=lfs merge=lfs -text lockable
*.drw filter=lfs diff=lfs merge=lfs -text lockable
*.asm.1 filter=lfs diff=lfs merge=lfs -text lockable
*.prt.1 filter=lfs diff=lfs merge=lfs -text lockable
*.drw.1 filter=lfs diff=lfs merge=lfs -text lockable
*.asm.* filter=lfs diff=lfs merge=lfs -text lockable
*.prt.* filter=lfs diff=lfs merge=lfs -text lockable
*.drw.* filter=lfs diff=lfs merge=lfs -text lockable

### 3D Neutral
*.stp filter=lfs diff=lfs merge=lfs -text lockable
*.step filter=lfs diff=lfs merge=lfs -text lockable
*.igs filter=lfs diff=lfs merge=lfs -text lockable
*.iges filter=lfs diff=lfs merge=lfs -text lockable
*.x_t filter=lfs diff=lfs merge=lfs -text lockable
*.x_b filter=lfs diff=lfs merge=lfs -text lockable
*.sat filter=lfs diff=lfs merge=lfs -text lockable
```

* `.gitignore` 파일 예제

```
### Solidworks
~$*.SLDPRT
~$*.SLDASM

### Creo
std.out
current_session.pro
datafile.ers
errors.lst.*
fix_params.log
*.acc
*.crc
*.err.*
*.idx
*.inf.*
*.log.*
std.err
std.out
trail.txt.*
*.xpr
*.tst
*.acl
*.lst
*.mbx
*.ncl.*
*.ncl_a.tab
*.ncl_b.tab
*.ncl_c.tab
*.ncl_x.tab
*.ncl_y.tab
*.ncl_z.tab
*.tap
*.m_p
*.idx
*.log
*.lsl.*
*.bak
*.pcf
*.inf
*.xml
```

* 새로운 저장소를 만들때 자동으로 `.gitattribute` 파일과 `.gitignore` 파일이 적용되도록 global로 셋팅하는 것이 적절한지는 아직 판단하지 못했다.  당분간은 약간의 불편함을 감수하고, 새로운 저장소를 생성할 때 해당 파일들을 직접 만들어주자.

* 좀 더 확실한 자동화를 위해서는 git hook 기능을 더 설정해서 사용해 볼 수도 있겠지만 여기서는 생략하자.  (좀 더 연구해 보고)

* 필요하다면, pdf/png 포멧의 도면을 Diff 해 준다던가, 또는 3D 부품들의 형상을 Diff해 주는 외부 프로그램을 연결해서 Diff 기능을 확장하는 것도 충분히 가능하다.  이런 셋팅이 충분히 가능한 것은 확인이 끝났지만, 테스트는 아직 실시해 보지 못했다.

* pdf/png 이미지의 Diff는 ImageMagik이 가장 적합하고, 3D 모델은 스크립트로 해당 파트 파일을 stl 포멧으로 변환한 후 가벼운 NodeJS 기반으로 웹브라우저로 Diff 결과를 보여주는 구현체들을 연결하면 끝날 것이다.

* 다만 이런 	외부 Diff 프로그램들을 SourceTree상에서 그대로 연결해서 연동이 잘 될지는 확인 및 테스트가 필요하다.


## SourceTree 사용방법
* 생략한다...  알아서 파악하면 될 것이다.



## 예제 스크린샷

* Gitea Example

![screenshot-2017-10-2 lfs_test](https://user-images.githubusercontent.com/12775748/31081948-70a1b76e-a7c8-11e7-897f-996a7c5477c7.png)

* SourceTree Example

![image 1](https://user-images.githubusercontent.com/12775748/31082516-2fd589e8-a7ca-11e7-9fda-e57e77f5594a.png)



## 추가 고찰

* 개인적으로 또는 소수의 설계자가 참여한 팀에서, 버전관리 용도로 이렇게 구축해서 사용하는 것은 좋은 방법이 될 수 있다고 생각된다.

* Mechanical CAD, Electronic CAD 모두 적용 가능하다.

* 여기에 Software 프로젝트와 통합하는 건 일도 아닐 것이다.

* 다만, 하드웨어 설계자들이 과연 Git의 개념을 저항없이 받아들이고 그 장점을 취할 수 있느냐는 여전히 의문으로 남는다.  좀 어그레시브한 성향의 설계자들이라면 가능할 수도 있지 않을까...  하지만 현업에서 만나볼 수 있는 대부분의 하드웨어 설계자들은 새로운 툴이나 방법론을 받아들이는데 굉장한 저항감을 보이는 경우가 많다.  그들의 강고한 선입견이나 고집을 풀어주는 것이 아마 도입 성패를 가늠할 것이다.

* 다만, 여기서 확인가능한 것은, 별도 소프트웨어 추가 개발 없이, 현재 있는 도구들 만으로도 충분히 Git 기반 PDM 구축이 가능하다는 것을 확인했다는 점이다.

* Git에 대해 개념이 전혀 없는 초보자가 SourceTree를 곧바로 사용하기에는 진입장벽이 여전히 존재한다.  이런 진입장벽을 완전히 없애려면, SourceTree를 대체할 수 있는 PDM 전용의 클라이언트 앱이 개발될 필요가 있다.

* 이런 클라이언트 앱을 개발한다면, 내 소견으로는 Electron/JS 기반으로 만드는 것이 가장 좋지 않을까 한다.  일단 일정 수준 이상의 웹개발자라면 Electron 앱 개발에 별다른 어려움을 느낄 것 같지 않아서, 개발자 확보가 용이할 것이다.  또 자연스럽게 멀티 플랫폼 앱이 된다.  아울러 NodeJS 기반의 좋은 툴들을 그냥 땡겨서 쓰기가 좋다(예컨데 3D Diff 같은 것들).

* 향상을 위해 사용자와의 접점이 되는 클라이언트 앱의 개발이 필수적이겠지만, 서버쪽 개발은 기존의 것을 그대로 사용해도 무방하다고 생각한다.

* 아울러, SourceTree가 PDM용도로 완전한 기능을 갖추고 있지는 못하다.  예컨데, Git LFS에서는 기본적인 기능만 구현되어 Lock-Unlock을 변경할 수 있는 파일별 Lock 기능이 구현되어 있지만, SourceTree에서는 이 Lock 기능이 GUI에 적용되어 있지 않다.  따라서 현재로서는 Lock 기능을 사용하려면 커맨드 명령으로 할 수 밖에 없어 현실적이지 않다.  따라서 새로운 PDM 전용 클라이언트 앱을 개발할 때, LFS Lock 기능까지 반영해야 할 것이다.
