---
layout: post
published: true
title: ODA tools to touch dwg files
subtitle: ODA tools for 2D CAD
date: '2020-06-22'
bigimg: /img/bigimg50.jpg
image: >-
  https://media-exp1.licdn.com/dms/image/C4D0BAQE4PBaLT8EahQ/company-logo_200_200/0?e=2159024400&v=beta&t=-3hxihHaeNzMarUIdhsRgZcKXgZ2KK6SLASToHPy_Wo
tags: software
---
## Open Design Alliance

https://www.opendesign.com/


## Ubuntu 18.04에 설치하기

* Ubuntu 18.04의 qt5-default 패키지는 qt 5.9 버전인데 의존성이 맞지 않으므로 qt 5.14를 설치해 주어야 한다.
* 다행히 qt 5.14의 ppa 저장소가 있어서 이것을 사용해서 빠르게 설치한다.

```bash
sudo add-apt-repository ppa:beineri/opt-qt-5.14.0-bionic
sudo apt install qt514-meta-full
```

* 단, 이때 설치되는 장소가 `/opt/qt514/`이므로, 경로를 잡아주어야 한다.
* `~/.zshrc` 또는 `~/.bash`에 다음 구문을 추가해서 경로 변수를 잡아준다.

```bash
# qt514
export PATH="/opt/qt514/bin:$PATH"
export LD_LIBRARY_PATH="/opt/qt514/lib:$LD_LIBRARY_PATH"
```

* __ODA File Converter__ 설치하기
* 이 툴은 디렉토리를 지정해 주면 해당 디렉토리의 모든 2D CAD 파일을 다른 버전으로 일괄 변환해 준다.
* dwg 2018 버전까지 지원된다.
* https://www.opendesign.com/guestfiles/oda_file_converter

```bash
wget https://download.opendesign.com/guestfiles/ODAFileConverter/ODAFileConverter_QT5_lnxX64_7.2dll.deb
sudo dpkg -i ODAFileConverter_QT5_lnxX64_7.2dll.deb
```

* __ODA Drawing Explorer__ 설치하기
* 이 툴은 그냥 뷰어가 아니고, 어느정도의 편집이나 그리기도 되는 간략화된 2D CAD라고 보면 될 것 같다.
* 단점은 한글지원이 안 되고 폰트 설정이 안된다.
* 대신 dwg 2018 버전까지 확실히 지원되는 장점이 있고, 3D 영역까지 지원된다.

* https://www.opendesign.com/guestfiles/oda_drawings_explorer
* https://www.opendesign.com/guestfiles/oda_drawings_explorer/reference

```bash
wget https://download.opendesign.com/guestfiles/ODADrawingsExplorer/ODADrawingsExplorer_QT5_lnxX64_7.2dll.deb
sudo dpkg -i ODADrawingsExplorer_QT5_lnxX64_7.2dll.deb
```

* 설치후 자동으로 만들어지는 desktop 파일은 환경변수 문제로 그대로 실행이 안되기 때문에, 환경변수를 잡아준 것으로 대체한다.
* 다음과 같이 desktop 파일들의 내용을 변경해 준다.

```bash
sudo nano /usr/share/applications/ODADrawingsExplorer_21.5.0.0.desktop
```

편집기에서 `Exec=...` 부분을 다음과 같이 대체한다.

```
Exec=env LD_LIBRARY_PATH=/opt/qt514/lib:$LD_LIBRARY_PATH; /usr/bin/ODADrawingsExplorer %U
```

또

```bash
sudo nano /usr/share/applications/ODAFileConverter_21.5.0.0.desktop
```

편집기에서 `Exec=...` 부분을 다음과 같이 대체한다.

```
Exec=env LD_LIBRARY_PATH=/opt/qt514/lib:$LD_LIBRARY_PATH; /usr/bin/ODAFileConverter %U
```

* ODA Drawing Explorer 실행 상태

![20200622_000541_1366x768](https://user-images.githubusercontent.com/12775748/85228621-4f8f5200-b41f-11ea-8fe6-4bf008e2d571.png)

끝!