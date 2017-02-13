---
layout: post
published: true
title: PDF_AutoGeneration_for_CREO
date: '2017-02-13'
subtitle: 'Auto Batch Generation of PDF, DXF, DWG drawings from CREO DRW'
bigimg: /img/bigimg32.jpg
image: 'https://pbs.twimg.com/profile_images/739939031157350400/LL-G039B.jpg'
tags: software
---

  
## CREO Automation Methods
* Ref : http://3cad.blogspot.kr/2015/08/creo-api-creo-tool.html
* PTC CREO의 자동화된 작업을 구현하기 위해 다음 방법들을 고려할 수 있다.
  - __Distributed BATCH__ : 일반적으로 권장되는 표준 방법이지만, GUI 툴이기 때문에 커맨드라인 명령으로 일괄처리하는데는 부적합한 것 같다.  자세한 기술 사항은 나도 잘 모르겠다.
  - __Toolkit__ : 표준적으로 제공되는 C++ API이다.  이걸 기반으로 C,C++ 프로그램을 작성해서 자동화 작업을 구현할 수 있다.  다만 Toolkit을 사용하려면 별도로 라이센스를 구매해야 하고, 또 제공되는 API들을 학습해야 하며, 개발환경을 구축하고 C코딩을 하고 컴파일하는 등 일이 복잡해진다.
  - __JLink__ : Java로 짤 수 있는 API이다.  이걸로 원하는 작업이 가능한지는 정확히 파악하지 못했다(Toolkit보다 다룰 수 있는 기능상의 제약이 있기 때문).
  - __VB API__ : MS 비주얼 베이직 API이다.  없는걸로 치자.
  - __WebLink__ : 액티브X로 작동시키는 거다.  없는걸로 치자.
  - __Trail__ : Trail 파일을 잘 만들어 놓은 후, CREO를 GUI 없이 실행시키되 Trail 파일이 그대로 수행되도록 잘 셋팅하면 어느정도의 일이 구현 가능하다.
* 이상의 방법 중에서, 제일 마지막 Trail 파일을 이용한 일괄작업을 시도해 볼 만 하다.
* 이유는, 커맨드라인에서 그대로 간단하게 작동 가능하기 때문에 배치파일로 구성하기가 용이하기 때문이다.


## __Trail__ 방법에 관한 선행 조사

* [Batch mode Pro/Engineer](http://ossandcad.blogspot.kr/2008/04/batch-mode-proengineer.html)
  - `proe.exe` 실행시 `-g:no_graphics` 옵션을 줘서 실행시키면, GUI 없이 실행된다는 걸 알려주고 있다.  즉 화면에 아무런 GUI 창도 뜨지 않는다.
  - 이때, 뒤에 원하는 Trail 파일을 적어주면 그 파일에 지시된 레시피대로 백그라운드에서 작동이 이루어진다는 거다.
* 현재 사용중인 시스템은 CREO 3.0 Parametric이므로, 이에 맞게 일단 다음 명령을 써 본다.

```
cd /D E:\PTC\CREO3_STARTUP
"E:\PTC\CREO3\Creo 3.0\M010\Parametric\bin\parametric.exe"
```

* 그러면, 아무 옵션 없이 실행했기 때문에, `E:\PTC\CREO3_STARTUP` 폴더 안에 있는 `config.pro` 설정을 반영해서 정상 실행된다.

* 이번에는 `-g:no_graphics` 옵션을 줘서 해 보자.

```
cd /D E:\PTC\CREO3_STARTUP
"E:\PTC\CREO3\Creo 3.0\M010\Parametric\bin\parametric.exe" -g:no_graphics
```

* 이렇게 하니까, 과연 아무런 GUI창이 뜨지 않는다.  윈도우 작업관리자에서 확인해 보니, `xtop.exe`프로세스가 떠서 실행되어 있다는 것이 보인다.

* 문제는 `xtop.exe` 프로세스가 자동으로 죽지는 않는다는 것이다.  강제로 죽여보자.

```
taskkill -f -im xtop.exe
```

* 이제 Trail 파일을 사용해서 어떤 일을 해 보자.
* 우선 제대로 확인하기 위해 GUI를 띄우면서 trail 파일이 실행되도록...

```
cd /D E:\PTC\CREO3_STARTUP
"E:\PTC\CREO3\Creo 3.0\M010\Parametric\bin\parametric.exe" "C:\Users\dong\Desktop\trail.txt"
```

* 실행이 잘 되는걸 확인했다.  그럼 이제 GUI 없이 해 보자.

```
cd /D E:\PTC\CREO3_STARTUP
"E:\PTC\CREO3\Creo 3.0\M010\Parametric\bin\parametric.exe" -g:no_graphics "C:\Users\dong\Desktop\trail.txt"
```

* 역시 잘 된다.  이때는, 해당 Trail 파일을 수행 완료한 후에 자동으로 xtop.exe 프로세스가 종료되기 때문에, taskkill을 억지로 실행해 줄 필요가 없다는 점이다.

* 다만, 간혹 Trail 파일에 자동 기록되지 않는 입력 동작이 있는 경우에는, no_graphic 상태에서는 사용자 입력을 넣을 방법이 없기 때문에 그냥 붕 떠 있는 상태로 결론이 안날 수도 있으므로 여러번의 테스트를 하면서 이런 경우가 없도록 잡아줘야 할 것 같다.

* 이제 문제는 Trail 파일을 잘 작성하는 것 뿐이다.  Trail 파일 작성 요령을 학습해야 하겠다...
  - Trail 파일 작성 문법을 체계적으로 알려주는 문서는 아직 발견 못했다.
  - Creo 사용시 자동으로 생성되는 Trail 파일을 들여다 보면서 참고하는 것이 일차적이긴 하지만, 이렇게 생성되는 Trail 파일은 마우스 버튼을 누른 좌표가 직접 찍혀있거나 해서 알아보기가 상당히 난해한 문제가 있다.  마우스 버튼 좌표 따위가 아니라 전달되는 아규먼트들을 깨끗하게 써주고 싶은데...
  - 정 안되면, 필요한 절차에 들어가는 명령들을 전부 Mapkey로 설정해 준 후, Trail 파일 자동 작성되도록 Mapkey로만 동작을 기록하고, 그것을 편집해서 재구성해주는 방법이라도 써야 할 듯.  이건 무식하긴 해도 확실히 동작은 되리라 기대한다. [참고1](https://creomapkeys.wordpress.com/creo-mapkeys/creo-create-mapkey-to-run-trail-file/) [참고2](https://gist.github.com/veggielane)
  - 또 Trail 파일의 마지막에는 단 하나의 캐리지리턴만 허용된다고 한다. [참고](https://creomapkeys.wordpress.com/2014/07/28/creo-exits-prematurely-during-trail-file-execution/)
* 그리고, 배치파일 내에서 exe 파일을 실행할 때는 앞에 `start` 구문을 써 주는 것이 좋겠다.


## Trail 파일 작성에 관한 정보
* [Trail Files – Session](https://creomapkeys.wordpress.com/creo-trail-files/)
* [Excel driven PROE using trail file & Macro](http://www.eng-tips.com/viewthread.cfm?qid=357697)
* [Script to build trail file based on list of files?](https://www.ptcusercommunity.com/thread/140525)
* [Gen-Release-List.zip](https://www.ptcusercommunity.com/servlet/JiveServlet/download/472054-125386/Gen-Release-List.zip) : Batch 파일로 Trail 파일을 자동 생성하는 예제
* [이상 예제의 Trail 파일 내용을 알아보기 쉽게 설명해 놓은 엑셀 시트](https://creomapkeys.files.wordpress.com/2015/03/trailfile_delete_table1.xls)
* 대충 위의 것들을 봐도 아직 충분한 정보가 부족하다...
* 추가로 더 찾아본 것은...
  - [Anatomy of a Trail File, Part 1](http://inversionconsulting.blogspot.kr/2008/05/proe-anatomy-of-trail-file-part-1.html)
  - [Anatomy of a Trail File, Part 2](http://inversionconsulting.blogspot.kr/2008/05/proe-anatomy-of-trail-file-part-2.html)
  - [Anatomy of a Trail File, Part 3](http://inversionconsulting.blogspot.kr/2008/08/proe-anatomy-of-trail-file-part-3.html)
* 이건 좀 도움이 되는 것 같다.
* 일단 다음 요약 사항은 1차적으로 참고...
  - `< `으로 시작하는 행은 전부 다 지워버려도 무방함. (뭔지 잘 모름)
  - `!`으로 시작하는 행은 주석이므로 삭제해도 무방함.
  - `!%`으로 시작하는 행은 응답 메시지이므로 삭제해도 무방함.
  - `~ `으로 시작하는 행만이 의미가 있음.
  - 행의 마지막이 ` \`으로 끝나는 것은 다음 행과 계속 한 행으로 연결된다는 의미.

## Trail 연습

* 파일을 열고, 그것을 빠르게 pdf로 저장

```
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
! 파일 열기
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
~ Command `ProCmdModelOpen`
~ Activate `file_open` `file_open`
~ Update `file_open` `Inputname` `F:\\2016_BACKUP_DODAAM\\TRCWS\\3D\\20160822_TRCWS\\trcws_cock2_hook_k6.drw`
~ Activate `file_open` `Open`
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
! pdf 출력 : pdf 출력은 되긴 하는데, 도면 위치가 전체적으로 위로 올라붙어 버리는 오류가 있음
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
~ Command `ProCmdQuickExport` 
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
! 종료
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
~ Close `main_dlg_cur` `main_dlg_cur`
~ FocusIn `UI Message Dialog` `yes`
~ Activate `UI Message Dialog` `yes`
!End of Trail File

```


* 파일을 열고, 그것을 약간 조건을 설정해 준 후 pdf로 출력

```
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
! 파일 열기
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
~ Command `ProCmdModelOpen`
~ Activate `file_open` `file_open`
~ Update `file_open` `Inputname` `F:\\2016_BACKUP_DODAAM\\TRCWS\\3D\\20160822_TRCWS\\trcws_cock2_hook_k6.drw`
~ Activate `file_open` `Open`
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
! pdf 출력 : 여전히 도면 위치가 위로 올라붙는다.
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
~ Command `ProCmdExportPreview`
~ Command `ProCmdDwgPubSettings` 
~ Select `intf_profile` `pdf_export.pdf_color_depth` 1 `pdf_mono`
~ Open `intf_profile` `pdf_export.pdf_raster_dpi`
~ Close `intf_profile` `pdf_export.pdf_raster_dpi`
~ Select `intf_profile` `pdf_export.pdf_raster_dpi` 1 `600`
~ Activate `intf_profile` `pdf_export.pdf_launch_viewer` 0
~ Activate `intf_profile` `OkPshBtn`
~ Command `ProCmdDwgPubExport` 
~ Activate `file_saveas` `OK`
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
! 종료
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
~ Close `main_dlg_cur` `main_dlg_cur`
~ FocusIn `UI Message Dialog` `yes`
~ Activate `UI Message Dialog` `yes`
!End of Trail File

```

* 이상 두 가지 방법을 연습해 보았는데, 문제는 이때 pdf로 나온 결과물이 그냥 수동으로 할 때와 다르다는 것이다.  다른 점은, 도면이 약간 위로 올라붙어 생성된다는 건데, 아마 Trail 파일이 순차적으로 실행시 시스템 반응 속도보다 너무 빨리 진행되기 때문이 아닐까 싶다.
* 이를 해결하기 위해, `config.pro` 파일에 `trail_delay 5`로 각 단계마다 5초씩 딜레이를 줘서 실행되도록 해서 다시 시도해 보았다.  결과는... 똑같다.  해결이 안된다.  이런!
* 그런데, 이걸 그냥 두고 여러개의 도면을 순차적으로 출력시켜보니 정상적으로 또 나온다.  원인은 모르겠으나 CREO 버그로 생각된다.


## Batch 파일 작성

* 이제 Trail 명령 체계를 대략 파악했으므로, 이것을 생성해 주는 Batch 파일을 작성하였다.  문법이 까다로웠기 때문에 이리저리 검색을 해 가면 맞췄다.
* 구성은 다음과 같다.
  - __BatchSubstitute.bat__ : 인터넷에서 받은 텍스트파일 내용 수정 유틸리티.
  - __DymaxionKim_Settup.bat__ : 사용자환경변수 설정 및 컨텍스트메뉴 등록.  레지스트리를 건드리기 때문에 실행할 때는 관리자권한으로 해야 함.
  - __DymaxionKim_PurgeClear.bat__ : 앞서 만들었던 doClear.bat 파일의 이름을 변경하여 포함시킴.
  - __DymaxionKim_drw2pdfdxfdwg.bat__ : 자동으로 drw 도면파일을 모두 한꺼번에 pdf, dxf, dwg 파일로 만들어냄.


## 사용법
* 이들 배치파일들을 전부 한 폴더에 넣고, `config,pro` 설정파일이 있는 Creo의 기본 Startup 장소에 `/BATCH` 폴더를 만들고 그 안에 넣는다.
* 텍스트편집기로 `DymaxionKim_Settup.bat` 파일을 열어서, 다음 부분의 내용을 자신의 환경에 맞게 경로 부분만 수정해 준다.  이때 경로 맨 마지막에 `\`는 붙이지 않도록 주의한다.

```
setx StartupPath "E:\PTC\CREO3_STARTUP"
setx ParametricPath "E:\PTC\CREO3\Creo 3.0\M010\Parametric\bin"
```

* 탐색기에서 `DymaxionKim_Settup.bat` 파일을 마우스 우클릭해서 `관리자 권한으로 실행`해 최초 셋팅해 준다.
* 이제 모든 프로그램을 다 끄고, 윈도우를 로그아웃/로그인하거나 재부팅한다. (사용자환경변수가 시스템에 적용되도록)
* 이제 설계작업을 하는 폴더를 탐색기로 찾아서, 해당 폴더아이콘을 마우스 우클릭 하면 컨텍스트메뉴가 추가되어 있음을 확인할 수 있다.
* `D3_drw2pdfdxfdwg` 실행 전에 반드시 `D2_PurgeClear`를 먼저 실행해서 청소 작업을 해 주도록 한다.
* 유의사항
  - 작업폴더에 `PDF`, `DXF`, `DWG` 폴더가 생성되면서 그 안에 각 도면파일들이 포멧별로 저장된다.
  - 이때 기존의 `PDF`, `DXF`, `DWG`가 남아있을 경우 전부 싹 다 먼저 지우고 새로 생성하기 때문에 주의하도록 한다.
  - `D3_drw2pdfdxfdwg` 실행중에 Creo가 뜨면서 Trail로 순차적인 작업이 이루어지는 과정을 볼 수 있는데, 만약 이것을 중도에 준단시키고 싶다면, 제일 확실한 방법은 작업관리자에서 `xtop.exe` 프로세스를 강제종료시키는 것이다.
* 테스트로 이것을 실행해 봤을 때, 다음 현상을 볼 수 있었다.
  - 109개의 부품도면을 작업시킬 때, 소요시간은 대략 20분 정도 걸린다.
  - CPU 코어는 당연하겠지만 1개만 점유한다.
  - Creo Parametric 자체를 실행시키는 것이므로, 상당히 무거운 느낌이 든다.
  - 때문에 가끔 이유없이 얼어붙거나 오류로 인해 작업이 실패하는 경우도 있을 수 있다.
  - 무거운 전체 어셈블리 도면은 가급적 제외시키고, 비교적 가벼운 부품도면들로만 작업시킬 경우에는 그럭저럭 동작에 크게 지장은 없어 보인다.
  - 실패를 방지하기 위해서는 데이타를 최대한 깨끗한 상태로 만들어준 후에 실행하는 것이 좋겠다.  도면에 걸린 외부참조 중에서 업데이트가 안되어 있거나 링크가 깨진 오브젝트가 있을 경우, 상정하지 않은 팝업이 뜨거나 그냥 얼어붙거나 기타등등 예측불가하므로 대응이 안될 수 있다.

## 소스코드

* BatchSubstitute.bat

```
@echo off
REM -- Prepare the Command Processor --
SETLOCAL ENABLEEXTENSIONS
SETLOCAL DISABLEDELAYEDEXPANSION

::BatchSubstitude - parses a File line by line and replaces a substring"
::syntax: BatchSubstitude.bat OldStr NewStr File
::          OldStr [in] - string to be replaced
::          NewStr [in] - string to replace with
::          File   [in] - file to be parsed
:$changed 20100115
:$source http://www.dostips.com
if "%~1"=="" findstr "^::" "%~f0"&GOTO:EOF
for /f "tokens=1,* delims=]" %%A in ('"type %3|find /n /v """') do (
    set "line=%%B"
    if defined line (
        call set "line=echo.%%line:%~1=%~2%%"
        for /f "delims=" %%X in ('"echo."%%line%%""') do %%~X
    ) ELSE echo.
)

```

* DymaxionKim_Settup.bat

```
title DymaxionKim_Settup
REM 2017-02-13
REM by Dymaxion.Kim@gmail.com

@echo on

REM Replace to your path.
REM  StartupPath : Where exists 'config.pro' file.
REM  ParametricPath : Where exists 'parametric.exe' and 'purge.bat' file.
setx StartupPath "E:\PTC\CREO3_STARTUP"
setx ParametricPath "E:\PTC\CREO3\Creo 3.0\M010\Parametric\bin"

REM Purge Command in Context Menu
reg add "HKEY_CLASSES_ROOT\Folder\shell\D1_Purge" /ve /d "D1_Purge"
reg add "HKEY_CLASSES_ROOT\Folder\shell\D1_Purge\command" /ve /d "C:\Windows\system32\cmd.exe /C cd /D %%1 & \"%ParametricPath%\purge.bat\""

REM DymaxionKim_PurgeClear Command in Context Menu
reg add "HKEY_CLASSES_ROOT\Folder\shell\D2_PurgeClear" /ve /d "D2_PurgeClear"
reg add "HKEY_CLASSES_ROOT\Folder\shell\D2_PurgeClear\command" /ve /d "C:\Windows\system32\cmd.exe /C cd /D %%1 & \"%StartupPath%\BATCH\DymaxionKim_PurgeClear.bat\""

REM DymaxionKim_drw2pdfdxfdwg Command in Context Menu
reg add "HKEY_CLASSES_ROOT\Folder\shell\D3_drw2pdfdxfdwg" /ve /d "D3_drw2pdfdxfdwg"
reg add "HKEY_CLASSES_ROOT\Folder\shell\D3_drw2pdfdxfdwg\command" /ve /d "C:\Windows\system32\cmd.exe /C cd /D %%1 & \"%StartupPath%\BATCH\DymaxionKim_drw2pdfdxfdwg.bat\" %%1"

```

* DymaxionKim_PurgeClear.bat

```
title DymaxionKim_PurgeClear
REM 2017-02-13
REM by Dymaxion.Kim@gmail.com

@echo on

REM Start

REM Purge
call %ParametricPath%\purge.bat

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

* DymaxionKim_drw2pdfdxfdwg.bat

```
title DymaxionKim_drw2pdfdxfdwg for CREO 3.0 Parametric
REM 2017-02-13
REM by Dymaxion.kim@gmail.com

@echo on
set WorkPath=%1
REM Start
if exist %1\temp.txt ( echo y| del %1\temp.txt > nul )
if exist %1\dir.txt ( echo y| del %1\dir.txt > nul )
if exist %1\trail.txt ( echo y| del %1\trail.txt > nul )
if exist %1\PDF\ ( echo y| rmdir /s %1\PDF\ > nul )
if exist %1\DWG\ ( echo y| rmdir /s %1\DWG\ > nul )
if exist %1\DXF\ ( echo y| rmdir /s %1\DXF\ > nul )
mkdir %1\PDF > nul
mkdir %1\DWG > nul
mkdir %1\DXF > nul

REM Drawing Files List
dir /b %1\*.drw.1 > %1\dir1.txt
call %StartupPath%\BATCH\BatchSubstitute.bat .drw.1 . %1\dir1.txt > %1\dir2.txt

REM Open Trail.txt
echo Generating Trail.txt ...
echo !trail file version No. 1800 >> %1\trail.txt
echo ! Compitable for Creo 3.0 by PTC Inc. >> %1\trail.txt
echo ! by Dymaxion.Kim@gmail.com >> %1\trail.txt

for /f "delims=" %%i in (%1\dir2.txt) do (
	echo ! >> %1\trail.txt
	echo ! Open a Drawing File >> %1\trail.txt
	echo ~ Command `ProCmdModelOpen` >> %1\trail.txt
	echo ~ Activate `file_open` `file_open` >> %1\trail.txt
	echo ~ Update `file_open` `Inputname` `%WorkPath:\=\\%\\%%idrw` >> %1\trail.txt
	echo ~ Activate `file_open` `Open` >> %1\trail.txt
	echo ! Output pdf >> %1\trail.txt
	echo ~ Command `ProCmdExportPreview` >> %1\trail.txt
	echo ~ Command `ProCmdDwgPubSettings` >> %1\trail.txt
	echo ~ Select `intf_profile` `pdf_export.pdf_color_depth` 1 `pdf_mono` >> %1\trail.txt
	echo ~ Open `intf_profile` `pdf_export.pdf_raster_dpi` >> %1\trail.txt
	echo ~ Close `intf_profile` `pdf_export.pdf_raster_dpi` >> %1\trail.txt
	echo ~ Select `intf_profile` `pdf_export.pdf_raster_dpi` 1 `600` >> %1\trail.txt
	echo ~ Activate `intf_profile` `pdf_export.pdf_launch_viewer` 0 >> %1\trail.txt
	echo ~ Activate `intf_profile` `OkPshBtn` >> %1\trail.txt
	echo ~ Command `ProCmdDwgPubExport` >> %1\trail.txt
	echo ~ Update `file_saveas` `Inputname` `%WorkPath:\=\\%\\PDF\\%%ipdf` >> %1\trail.txt
	echo ~ Activate `file_saveas` `OK` >> %1\trail.txt
	echo ! Output dxf >> %1\trail.txt
	echo ~ Activate `main_dlg_cur` `main_dlg_cur` >> %1\trail.txt
	echo ~ Command `ProCmdDwgPubSetDeliverable`  `DXF` >> %1\trail.txt
	echo ~ Command `ProCmdDwgPubExport` >> %1\trail.txt
	echo ~ Update `file_saveas` `Inputname` `%WorkPath:\=\\%\\DXF\\%%idxf` >> %1\trail.txt
	echo ~ Activate `file_saveas` `OK` >> %1\trail.txt
	echo ! Output dwg >> %1\trail.txt >> %1\trail.txt
	echo ~ Command `ProCmdDwgPubSetDeliverable`  `DWG` >> %1\trail.txt
	echo ~ Command `ProCmdDwgPubExport` >> %1\trail.txt
	echo ~ Update `file_saveas` `Inputname` `%WorkPath:\=\\%\\DWG\\%%idwg` >> %1\trail.txt
	echo ~ Activate `file_saveas` `OK` >> %1\trail.txt
	echo ! Close the Drawing File >> %1\trail.txt
	echo ~ Command `ProCmdDwgPubCloseExportPvw` >> %1\trail.txt
	echo ~ Command `ProCmdWinCloseGroup` >> %1\trail.txt
	echo ~ Command `ProCmdModelEraseNotDisp` >> %1\trail.txt
	echo ~ Activate `file_erase_nd` `ok_pb` >> %1\trail.txt
	)

REM Close Trail.txt
echo ! Close Creo Parametric >> %1\trail.txt
echo ~ Close `main_dlg_cur` `main_dlg_cur` >> %1\trail.txt
echo ~ FocusIn `UI Message Dialog` `yes` >> %1\trail.txt
echo ~ Activate `UI Message Dialog` `yes` >> %1\trail.txt
echo ! End of Trail File >> %1\trail.txt

REM Generate PDF,DXF,DWG
echo Starting Creo and Generating pdf,dxf,dwg ...
cd /d %StartupPath%
"%ParametricPath%\parametric.exe" %WorkPath%\trail.txt
REM "%ParametricPath%\parametric.exe" -g:no_graphics %WorkPath%\trail.txt
cd /d %1	

REM Clear
echo y| del %1\dir1.txt > nul
echo y| del %1\dir2.txt > nul
echo y| del %1\trail.txt > nul
echo y| del %1\DXF\*.log* > nul
echo y| del %1\DWG\*.log* > nul

echo JOB IS FINISHED!

REM exit
```