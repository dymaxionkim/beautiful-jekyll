---
layout: post
published: true
title: Purge_for_CREO
bigimg: /img/bigimg31.jpg
date: '2017-02-08'
subtitle: Purge for CREO
image: 'https://pbs.twimg.com/profile_images/739939031157350400/LL-G039B.jpg'
tags: software
---

## 개요
* 원래 CREO에 포함되어있는 purge.exe 프로그램은, 단순히 하위 버전넘버의 파일들을 일괄 삭제하는 기능만 가지는 단순한 커맨드라인 유틸리티이다.
* 그런데, 자체 PDM으로 CREO 데이타를 버전관리하려면, 이러한 CREO의 버전넘버를 먼저 자동적으로 정리해 줘야 할 필요가 있다.
* 우선 하위 버전 넘버의 파일들을 일괄 삭제하고, 남아있는 최종버전의 버전 넘버를 모두 1로 Rename해 주는 동작이 필요하다.  아울러, 불필요한 파일들도 삭제해 주는 것이 좋겠다.

## 밴치마킹

### Spekan Purge
* [재영아빠님의 블로그](http://proe.tistory.com/485)에 쓸만한 3rd party Purge 유틸리티가 소개되고 있는데, [Spekan Purge](http://innotiv-spekan-purge-tool.software.informer.com/)라고 한다.
* 이것은 GUI 툴이지만, 기능을 참고해서 선택해 볼 수 있겠다.

### [Purge Drive](http://www.wascotech.com/purgedrive/)
* 위의 것과 비슷하다.  GUI 프로그램이다.
* 유료.

### [CreoPurge](http://www.proesite.com/newframe.htm?/UTIL/creopurge.htm)
* 윈도우 탐색기의 컨텍스트메뉴(특정 폴더 아이콘에서 마우스 오른쪽 버튼을 누르면 나오는 메뉴)에 추가되는 프로그램.


## 기능 정의
* 하위 버전들을 일괄 삭제
* 최종 버전 넘버를 1로 Rename
* 특정 확장자 파일들을 삭제 (bom*, dat*, err*, ger*, txt*, igs*, inf*, 1st*, m_p*, tst*, out*, log*, ref*, ptd*, tst*, memb*, ers*, info*, lst*, shd* 등)
* 서브디렉토리까지 전부 다 훑을 수 있을 것

## 윈도우 시스템 명령어 예제

* `*.inf*` 파일을 서브디렉토리까지 전부 훑어서 삭제

```
del /s *.inf*
```

* [배치파일로 작성된 예제](https://www.ptcusercommunity.com/thread/130102)

```
::
:: Date   * 30 August 2015
:: Author * Kenneth J. Farley
::
:: Recursively traverses the directory structure, starting at the current
:: directory, and executes a purge and any other commands necessary. The
:: pseudocode for this is as follows
::
:: (1) Generate a list of directories
:: (2) For each of the directories
::     a. change to that directory, via a "pushd"
::     b. Execute the desired commands
::     c. change back to the original directory, via "popd"
::
 
@echo off
for /r /d %%d in ("*") do call :doPurge "%%d"
exit /b
 
::
:: This code is executed for each directory visited. The primary purpose is to
:: run the "purge" command, but it's also helpful to get rid of any other stray
:: files that Pro/E creates in the normal course of operation.
::
:: Note: The "2> nul" construct is used to throw away any "file not found" type
::       errors generated when the delete command doesn't find the target files
::       provided to it.
::
 
:doPurge
pushd %1
echo Processing %1
c:\ptc\purge
::
:: Windows generated files
::
del /ah Thumbs.db 2> nul
::
:: PTC General files
::
del APS00W07 2> nul
del current_session.pro 2> nul
del datafile.ers 2> nul
del errors.lst.* 2> nul
del fix_params.log 2> nul
del *.acc 2> nul
del *.crc 2> nul
del *.err.* 2> nul
del *.idx 2> nul
del *.inf.* 2> nul
del *.log.* 2> nul
del std.err 2> nul
del std.out 2> nul
del trail.txt.* 2> nul
del *.xpr 2> nul
del *.tst 2> nul
::
:: PTC Manufacturing files
::
del *.acl 2> nul
del *.lst 2> nul
del *.mbx 2> nul
del *.ncl.* 2> nul
del *.ncl_a.tab 2> nul
del *.ncl_b.tab 2> nul
del *.ncl_c.tab 2> nul
del *.ncl_x.tab 2> nul
del *.ncl_y.tab 2> nul
del *.ncl_z.tab 2> nul
del *.tap 2> nul
popd
exit /b
```


