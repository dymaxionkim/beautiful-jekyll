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
* 원래 CREO에 포함되어있는 purge.exe, purge.bat 프로그램은, 단순히 하위 버전넘버의 파일들을 일괄 삭제하는 기능만 가지는 단순한 커맨드라인 유틸리티이다.
* 그런데, 자체 PDM으로 CREO 데이타를 버전관리하려면, 이러한 CREO의 버전넘버를 먼저 자동적으로 정리해 줘야 할 필요가 있다.
* 우선 하위 버전 넘버의 파일들을 일괄 삭제하고, 남아있는 최종버전의 버전 넘버를 모두 1로 Rename해 주는 동작이 필요하다.  아울러, 불필요한 파일들도 삭제해 주는 것이 좋겠다.

## 기능
* 하위 버전들을 일괄 삭제
* 불필요한 특정 확장자 파일들을 모두 삭제
* 최종 버전 넘버를 1로 Rename


## Purge & Clear 배치파일 작성 (doClear.bat)

```
REM Purge & Clear
REM 2017-02-08
REM by Dymaxion.Kim@gmail.com

@echo on

REM Purge
call "E:\PTC\CREO3\Creo 3.0\M010\Parametric\bin\purge.bat"

REM Clear
REM del /ah Thumbs.db 2> nul

REM del /q APS00W07 2> nul
del /q current_session.pro 2> nul
del /q datafile.ers 2> nul
del /q errors.lst.* 2> nul
del /q fix_params.log 2> nul
del /q *.acc 2> nul
del /q *.crc 2> nul
del /q *.err.* 2> nul
del /q *.idx 2> nul
del /q *.inf.* 2> nul
del /q *.log.* 2> nul
del /q std.err 2> nul
del /q std.out 2> nul
del /q trail.txt.* 2> nul
del /q *.xpr 2> nul
del /q *.tst 2> nul

del /q *.acl 2> nul
del /q *.lst 2> nul
del /q *.mbx 2> nul
del /q *.ncl.* 2> nul
del /q *.ncl_a.tab 2> nul
del /q *.ncl_b.tab 2> nul
del /q *.ncl_c.tab 2> nul
del /q *.ncl_x.tab 2> nul
del /q *.ncl_y.tab 2> nul
del /q *.ncl_z.tab 2> nul
del /q *.tap 2> nul

del /q *.m_p 2> nul
del /q *.idx 2> nul
del /q *.log 2> nul
del /q *.lsl.* 2> nul
del /q *.bak 2> nul
del /q *.pcf 2> nul
del /q *.inf 2> nul

rename *.prt.* *.1 2> nul
rename *.asm.* *.1 2> nul
rename *.drw.* *.1 2> nul
rename *.frm.* *.1 2> nul
rename *.gph.* *.1 2> nul
rename *.win.* *.1 2> nul
rename *.tbl.* *.1 2> nul
rename *.sym.* *.1 2> nul

exit
```


## Purge.bat을 컨텍스트 메뉴에 등록하기

* 윈도우 탐색기에서, 특정 작업 폴터 아이콘에서 마우스 오른쪽 버튼을 누르면 나오는 컨텍스트 메뉴에 Purge를 추가하려면...

* cmd를 관리자 권한으로 실행한다.

```
단축키 : WindowsKey+X, A
```

* 다음 명령을 쳐 넣는다. (purge.bat의 경로명은 확인후 다르면 수정할 것)

```
reg add "HKEY_CLASSES_ROOT\Folder\shell\Purge" /ve /d "Purge"
reg add "HKEY_CLASSES_ROOT\Folder\shell\Purge\command" /ve /d "C:\Windows\system32\cmd.exe /C cd /D %1 & \"E:\PTC\CREO3\Creo 3.0\M010\Parametric\bin\purge.bat\""
```

* 이제 윈도우 탐색기에서, 작업중인 폴더를 마우스 오른쪽 버튼으로 누르면 `Purge`가 메뉴 중에 뜨고, 그걸 누르면 해당 폴더가 Purge 된다.


## doClear.bat을 컨텍스트 메뉴에 등록하기

* 우선 작성된 doClear.bat 파일을 다음 경로에 갖다 놓는다. (편의상 purge.bat 파일과 같은 장소에 놓는 것.)

```
E:\PTC\CREO3\Creo 3.0\M010\Parametric\bin\doClear.bat
```

* 윈도우 탐색기에서, 특정 작업 폴터 아이콘에서 마우스 오른쪽 버튼을 누르면 나오는 컨텍스트 메뉴에 doClear를 추가하려면...

* cmd를 관리자 권한으로 실행한다.

```
단축키 : WindowsKey+X, A
```

* 다음 명령을 쳐 넣는다. (purge.bat의 경로명은 확인후 다르면 수정할 것)

```
reg add "HKEY_CLASSES_ROOT\Folder\shell\doClear" /ve /d "doClear"
reg add "HKEY_CLASSES_ROOT\Folder\shell\doClear\command" /ve /d "C:\Windows\system32\cmd.exe /C cd /D %1 & \"E:\PTC\CREO3\Creo 3.0\M010\Parametric\bin\doClear.bat\""
```

* 이제 윈도우 탐색기에서, 작업중인 폴더를 마우스 오른쪽 버튼으로 누르면 `doClear`가 메뉴 중에 뜨고, 그걸 누르면 해당 폴더가 Purge & Clear 된다.



### 밴치마킹
* Spekan Purge
  - [재영아빠님의 블로그](http://proe.tistory.com/485)에 쓸만한 3rd party Purge 유틸리티가 소개되고 있는데, [Spekan Purge](http://innotiv-spekan-purge-tool.software.informer.com/)라고 한다.
  - 이것은 GUI 툴이지만, 기능을 참고해서 선택해 볼 수 있겠다.

* [Purge Drive](http://www.wascotech.com/purgedrive/)
  - 위의 것과 비슷하다.  GUI 프로그램이다.
  - 유료.

* [CreoPurge](http://www.proesite.com/newframe.htm?/UTIL/creopurge.htm)
  - 윈도우 탐색기의 컨텍스트메뉴(특정 폴더 아이콘에서 마우스 오른쪽 버튼을 누르면 나오는 메뉴)에 추가되는 프로그램.
  
### 참고 예제
* [배치파일로 작성된 예제](https://www.ptcusercommunity.com/thread/130102)
* [Renumber 배치파일 예제](http://www.sharptechdesign.com/Utilities/Renumber_Bat.htm)