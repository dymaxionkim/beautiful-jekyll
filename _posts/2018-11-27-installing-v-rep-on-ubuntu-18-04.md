---
layout: post
published: true
title: Installing V-REP on Ubuntu 18.04
subtitle: 우분투 18.04에 V-rep를 설치해 보니 실패한다.  이를 해결하기 위한 선행작업.
date: '2018-11-27'
bigimg: /img/bigimg45.jpg
image: 'http://coppeliarobotics.com/images/v-rep-logo-pro-edu.png?crc=90231548'
tags: software
---

* 개발사 : http://coppeliarobotics.com/

* Ref : http://www.forum.coppeliarobotics.com/viewtopic.php?f=5&t=7288

* 의존성 해결

```bash
sudo apt install libboost-all-dev lua5.1 liblua5.1-0 liblua5.1-0-dev qtcreator qt5-default libqt5serialport5-dev
```

* QScintilla 컴파일 및 설치

  - Ref : file:///home/osboxes/Download/QScintilla_gpl-2.10.8/doc/html-Qt4Qt5/index.html

  - https://www.riverbankcomputing.com/software/qscintilla/download 으로 가서 `QScintilla_gpl-2.10.8.tar.gz` 다운로드후 압축풀기

  - 컴파일 및 설치

```bash
cd .../QScintilla_gpl-2.10.8/Qt4Qt5
qmake
make
sudo make install
```

* V-REP 다운로드

  - http://coppeliarobotics.com/downloads.html 이곳에서 원하는 버전 다운로드 및 압축풀기

  - 실행

```bash
cd .../V-REP_PRO_EDU_V3_5_0_Linux
./vrep.sh
```

* 헥헥...  이제 해 보자.

