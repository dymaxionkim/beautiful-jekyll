---
layout: post
published: true
title: Jupyter
subtitle: "과학자를 위한 40가지 이상의 프로그래밍 언어를 지원하는 오픈소스 대화식 환경"
date: '2017-01-23'
bigimg: /img/bigimg24.jpg
image: >-
  https://cloud.githubusercontent.com/assets/12775748/22197598/0e218c02-e196-11e6-8deb-7a829ffdd0b6.png
tags: software
---

## Jupyter?
* 뭔지 궁금하면 [공식 홈페이지](http://jupyter.org/) 가서 보자.

![Jupyter Logo](https://cloud.githubusercontent.com/assets/12775748/22197598/0e218c02-e196-11e6-8deb-7a829ffdd0b6.png)


## Jupyter를 사용하면 뭐가 좋아지나?
* 웹브라우저에서 모든 작업이 이루어져 편리해진다.
* 코딩과 문서화 작업을 한꺼번에 할 수 있다.
* 매일 일기 쓰듯이 코딩 연습을 할 수 있게 자연스럽게 습관이 든다.
* 재미있어진다.

## 어떻게 사용하나?
* 온라인에서 서비스를 제공해 주는 곳에 가서 이용해도 된다.
* 하지만 나의 데스크탑에 로컬로 설치해서 마음대로 환경을 설정해 가면서 쓰는것이 더 좋다.
* 작업한 노트북들은 Github에 push하면서 백업 효과를 노리자.

-----

# Jupyter Notebook 설치 및 환경셋팅
* 시스템 자체의 부하가 크지 않기 때문에 한 번 같이 올려본다.
* 자신의 서버/컴퓨터에서 Jupyter 서비스를 온라인으로 제공하게 되면, 자신이 사용하는 PC 마다 일일이 따로따로 설치해 줘야 하는 불편함에서 벗어날 수 있다.
* Python, Julia, Octave, Bash 커널 등을 넣어서 함께 제공하기로 한다.
* 본 환경구축 레시피는 다음 환경에서 테스트했다.
  - 우분투 16.04 계열 리눅스 머신


## Anaconda3 설치
* Anaconda 패키지를 설치하는게 가장 손쉽다.
* Anaconda 패키지에는, python과 과학기술용 각종 라이브러리들, 그리고 Jupyter 핵심 부분이 기본적으로 포함되어 있으며, 일반적인 python의 패키지 관리자인 pip 말고 전용 패키지 관리자인 conda도 들어있다.
* 다운로드 사이트 : <https://www.continuum.io/downloads#linux>
* 위 사이트에서 다운로드 할 버전의 주소를 복사한 다음, 아래와 같이 wget으로 NAS에 다운로드 받아도 된다.

```
cd ~
wget https://repo.continuum.io/archive/Anaconda3-4.2.0-Linux-x86_64.sh
```

* 다운로드 받은 설치파일을 실행한다.

```
bash Anaconda3-4.2.0-Linux-x86_64.sh
```

* 설치할 때 마지막에 bash 설정에 경로를 추가할지를 묻는데, 당연히 추가하도록 yes 해 준다.
* 이제 Anaconda 패키지는 모두 `~/anaconda3` 경로에 설치되어 있을 것이다.  sudo 권한으로 설치한 것이 아니므로, 자신이 마음대로 삭제할 수도 있다는 점을 유의한다.  또한 앞으로 새로 추가할 패키지들 역시 sudo 권한이 불필요할 것이다.


## Anaconda3 업데이트 및 셋팅
* Anaconda의 Python 패키지들을 전부 최신버전으로 업데이트하려면 다음 명령을 쓰면 된다.

```
conda update conda
conda update anaconda
```

## Jupyter를 위한 Python 환경 생성
* 고립된 Python 환경을 생성하여면 다음과 같은 식으로 하면 된다.  본 예에서는 JUPYTER라는 이름의 Python 환경을 만들고, 그 환경을 Activate 시키는 것이다.

```
conda create --name JUPYTER ipython
source activate JUPYTER
```

## Jupyter 설치
* 기본적인 패키지는 이미 Anaconda에 들어가 있지만, 확실히 하기 위해 Jupyter 설치 명령을 준다.

```
conda install jupyter
```

## Jupyter Notebook에 설치 가능한 커널
* Jupyter를 설치하면 기본적으로 Anaconda의 Python 언어가 기본적으로 들어가 있을 것이다.
* 하지만 여기에 추가하여 다른 언어들도 사용 가능하도록 할 수 있다.
* 가능한 언어들의 목록은 다음과 같다.
* <https://github.com/ipython/ipython/wiki/IPython-kernels-for-other-languages>


## Julia 커널 설치
* Julia 언어를 시스템에 설치하고, 이것을 Jupyter에서도 사용할 수 있도록 커널을 설치해 보자.
* 저장소를 등록하고, 설치.

```
sudo add-apt-repository ppa:staticfloat/juliareleases
sudo add-apt-repository ppa:staticfloat/julia-deps
sudo apt-get update
sudo apt-get install julia
```

* 기본적인 Julia 패키지 설치

```
julia
```

실행한 후, Julia 안에서 다음 명령을 넣어서 Julia 언어에서 사용할 확률이 가장 높은 모듈들을 추가 설치한다.

```
Pkg.init()
Pkg.add("Jewel")
Pkg.add("Images")
Pkg.add("PyPlot")
Pkg.add("IJulia")
Pkg.update()
quit()
```

* 패키지 설치 도중에 빌드 에러가 발생할 경우, 다음과 같이 의존성 있는 것들을 추가 설치해 주면 해결될 확률이 높다. (어떤 모듈의 경우에는 설치하면서 동시에 Build 작업이 진행되는 경우가 있다.)

```
sudo apt-get install build-essential cmake
```


## GNU Octave 커널 설치
* 이번에는 GNU Octave를 시스템에 설치하고, 이것을 Jupyter에서도 사용할 수 있도록 커널을 설치해 보자.
* 저장소를 등록하고, 설치.

```
sudo add-apt-repository ppa:octave/stable
sudo apt-get update
sudo apt-get install octave
```

* Octave 잘 실행되는지 확인

```
octave-cli
```

* Octave GUI 실행 확인

```
octave
```

* Octave GUI 실행 실패시 조치 (QT 설정파일 소유권을 root에서 현재 사용자로 변경) : 현행 배포한의 버그.

```
sudo chown -hR 계정:계정 ~/.config/octave
```

* 커널 설치 (sudo 불필요)

```
pip install octave_kernel
python -m octave_kernel.install
```


## Bash 커널 설치
* 이번에는 Bash를 시스템에 설치하고, 이것을 Jupyter에서도 사용할 수 있도록 커널을 설치해 보자.
* 커널 설치

```
pip install bash_kernel
python -m bash_kernel.install
```

## C 커널 설치
* 이번에는 C 언어를 Jupyter에서도 사용할 수 있도록 커널을 설치해 보자.  C 컴파일러는 이미 시스템에 gcc로 설치되어 있으므로 컴파일러는 별도로 설치할 필요가 없다.
* 참고 : https://github.com/brendan-rius/jupyter-c-kernel
* C 커널 설치

```
pip install jupyter-c-kernel
```

* 커널스펙 설정

```
cd ~
git clone https://github.com/brendan-rius/jupyter-c-kernel.git
mkdir ~/.local/share/jupyter/kernels/c_spec
cp ./jupyter-c-kernel/c_spec/kernel.json ~/.local/share/jupyter/kernels/c_spec/kernel.json
```



## 설치된 커널들 이상없는지 확인하기
* 아래 명령은 치면, 위에서 설치했던 커널들의 목록을 볼 수 있다.

```
jupyter kernelspec list
```


## Jupyter Notebook 작업 디렉토리 생성
* 아무데서나 실행할 수는 없으므로, 작업할 디렉토리를 따로 만들어주는게 보안상 좋겠다.  이왕이면 Github와 연동시키기 좋도록 한다.

```
mkdir ~/github/My-Jupyter-Notebooks
```

* Github 리모트 저장소와 연결하는 절차의 설명은 생략한다.


## Jupyter Notebook을 외부망에서 접속 가능하도록 설정하기
* 참고 : http://jupyter-notebook.readthedocs.io/en/latest/public_server.html
* 현재까지의 셋팅에서는, `http://localhost:8888`로만 연결 가능하다.
* 외부망에서 접속 가능하도록 하기 위해 설정 프로파일을 생성하고, 확인 및 수정한다.
* [참고 1](http://jupyter-notebook.readthedocs.org/en/latest/public_server.html#running-a-public-notebook-server), [참고 2](http://jupyter-notebook.readthedocs.org/en/latest/public_server.html#securing-a-notebook-server)
* 새로운 Jupyter Notebook 설정 프로파일을 생성.

```
jupyter notebook --generate-config
```

* 그러면 `/home/dong/.jupyter/jupyter_notebook_config.py` 파일이 새로 생겨난 것을 확인.
* 한편, 로그인을 위한 패스워드 해쉬코드를 만든다.  이와 관련된 기본적인 파이썬 함수가 있으므로, 파이썬 상태에서 이 함수를 이용해서 해쉬코드를 만든다.  우선 터미널에 `python` 쳐서 파이썬 REPL로 들어간 다음,

```
from notebook.auth import passwd
passwd()
```

위와 같이 명령을 때려주면 비밀번호를 치라고 나오는데 확인차 2번 쳐 주면 해쉬코드로 된 비밀번호 코드가 나온다.  해쉬코드를 긁어다 복사해 두거나 메모해 둔다.  그리고 python 콘솔을 빠져나오려면 

```
exit()
```

* 설정 프로파일을 편집기로 열어서 내용 확인. (대략 500줄을 좀 넘어가는 코드이고, 대부분 주석)

```
nano /home/계정/.jupyter/jupyter_notebook_config.py
```

* 편집기에서 다음 내용으로 해당 부분을 수정해 준다. 이중에서 포트 번호는 원하는걸로 바꾸면 되지만, 여기서는 8888로 하자.  각 행의 맨 앞에 주석기호 `#`의 유무를 잘 비교해서 확인하자.

```
c.NotebookApp.ip = '*'
c.NotebookApp.port = 8888
c.NotebookApp.notebook_dir = u'/home/계정/github/My-Jupyter-Notebooks'
c.NotebookApp.open_browser = False
`
* 그리고, 비밀번호 해쉬코드도 다음과 같은 형식으로 넣어준다.
`
c.NotebookApp.password = u'sha1:67c9e6어쩌구저쩌구71089e11aed'
```
* 완료되었으면 해당 편집기를 저장하고 종료.
* 서버 환경에 따라 방화벽으로 막혀 있을 수 있으므로 해당 포트를 뚫어준다.
```
sudo ufw allow 8888
```


## Jupyter Notebook 실행 테스트
* 다음 명령을 주면 실행된다.

```
jupyter notebook
```

* 자동으로 웹브라우저가 실행되지 않도록 하려면 이렇게 한다.

```
jupyter notebook --no-browser
```

* 특정한 디렉토리를 루트로 삼아 실행되도록 하려면 이렇게 한다.

```
jupyter notebook --notebook-dir='디렉토리경로'
```

* 이제 외부 컴퓨터의 웹브라우저로 다음 주소를 쳐서 들어가지는지 확인.

```
http://아이피주소:8888
```

비밀번호 로그인, 설치된 커널의 활성화 여부 등을 확인한다.
* 이상없이 잘 되면, 서버 터미널에서 `Ctrl+c`, `y`를 쳐서 종료한다.


## 부팅할 때 자동으로 Jupyter Notebook 실행되도록 설정
* 개인 서버에서 돌리려면 이런식으로 자동 스타트 설정을 해 주면 편리할 것이다.
* 쉘 스크립트를 편집해서 만든다.

```
nano ~/Start_Jupyter.sh
```

한 다음 다음 내용을 써 넣고 저장 후 종료.

```
#!/bin/bash
/home/계정/anaconda3/bin/jupyter notebook &
```

* 만든 쉘 스크립트를 실행 가능하도록 속성을 준다.

```
chmod +x ~/Start_Jupyter.sh
```

* 다음과 같이 rc.local 파일을 열어서 편집한다.

```
sudo nano /etc/rc.local
```

* 다음 내용을 추가한 후 저장하고 편집기 종료.

```
sudo -u 계정 /home/계정/Start_Jupyter.sh
```

* 서버 재부팅

```
sudo reboot now
```

* 만일 제대로 작동을 안한다면 다음 명령을 줘 본다.  ([참고](http://askubuntu.com/questions/765120/after-upgrade-to-16-04-lts-rc-local-not-executing-command/770033#770033))

```
sudo systemctl enable rc-local.service
```


## Jupyter Notebook Extensions 설치
* Anaconda를 이용해 설치된 Jupyter Notebook에는 Anaconda 자체적인 Extension이 이미 설치되어 있다.  별다른 조치 없이 슬라이드샷으로 프리젠테이션 해 주는 기능 등이 있어 편리하다.  ([참고](https://docs.continuum.io/anaconda/jupyter-notebook-extensions))
* 다만 여기서는 표준적인 Jupyter Notebook Extensions를 추가로 설치 시도한다.
* 참고 : <https://github.com/ipython-contrib/jupyter_contrib_nbextensions>

```
conda install -c conda-forge jupyter_contrib_nbextensions
```

* 단, 이 익스텐션은 64비트 버전만 제공되고 32비트 버전은 제공되지 않는다.  자신의 서버/컴퓨터가 32비트라면 사용할 수 없다.


## Jupyter Notebook Themes 설치
* 여러가지 방식으로 개발된 테마들이 있지만, 다음의 것이 가장 심플하고 설치 자체도 쉬운 것 같다.
* jupyterthemes : https://github.com/dunovank/jupyter-themes
* 설치는 다음 한 줄이면 끝난다.

```
pip install jupyterthemes
```

* 설치 후 적용 가능한 테마를 보기 위해 `jt -l`을 쳐 주면 다음과 같이 4가지 테마가 나온다.

```
onedork
grade3
oceans16
chesterish
```

* 이 중에서 grade3가 바탕이 흰 색의 테마이고, 나머지는 어두운 색이다.  시험삼아 다음 명령을 하나씩 줘 보자.

```
jt -t grade3 -T -N
```

* 원상복귀 하려면 `jt -r`을 주면 된다고 하는데, 해 봐도 원상복귀가 안된다! ㅠㅠ
* 강제로 원상복귀 시키려면, 원래의 오리지널 css 파일을 만들어서 집어넣어주면 될 것이다.
* `~/.jupyter/custom/custom.css` 파일을 만들고 편집기로 다음 내용을 집어넣으면 원래 오리지널 테마로 복원된다.

```
.rendered_html pre, .rendered_html code, pre, .CodeMirror, .prompt {
  font-family: 나눔고딕코딩, Consolas,"Andale Mono WT","Andale Mono","Lucida Console","Lucida Sans Typewriter","DejaVu Sans Mono","Bitstream Vera Sans Mono","Liberation Mono","Nimbus Mono L",Monaco,"Courier New",Courier,monospace;;
}
.rendered_html pre,
.rendered_html code {
    font-family: Consolas,"Andale Mono WT","Andale Mono","Lucida Console","Lucida Sans Typewriter","DejaVu Sans Mono","Bitstream Vera Sans Mono","Liberation Mono","Nimbus Mono L",Monaco,"Courier New",Courier,monospace;
	background-color: #f5f5f5;
}
.rendered_html pre {
	padding: 8.5px;
	border: 1px solid #ccc;
	border-radius: 2px;
}
.rendered_html p > code,
.rendered_html ul li code {
    border: solid 1px #e1e4e5;
    color: #E74C3C;
    padding: 0 5px;
    overflow-x: auto;
}
blockquote {
	background-color: #fcf2f2;
	border-color: #dFb5b4;
	border-left: 5px solid #dfb5b4;
	padding: 0.5em;
}
```

* 테마 때문에 일부 기능이 제한되거나 작동이 안되는 부분이 있는지 확인이 필요하다.
* 수동으로 직접 css 파일 수정을 해서 테마를 변경하려면 다음 페이지들을 참고.
  - <http://seokjoonyun.blogspot.kr/2016/08/jupyter-notebook-markdown-css.html>
  - <http://bryan7.tistory.com/850>
  - <http://stackoverflow.com/questions/32156248/how-do-i-set-custom-css-for-my-ipython-ihaskell-jupyter-notebook>


## Jupyter Lab
* 이제까지 설치해서 사용하는 환경은 바로 'Jupyter Notebook'이다.
* 그런데 이 UI가 마음에 안 드는지, 한 그룹에서 새롭게 Jupyter Lab을 개발하고 있다.

![JupyterLab](https://github.com/jupyterlab/jupyterlab/raw/master/jupyter-plugins-demo.gif)

* 현재 알파 릴리즈되어 설치해서 작동 시켜볼 수도 있다.
* 다만 아직 완전하게 기능구현,최적화,버그 등을 모두 잡은 상태는 아닌 것 같다.
* 다만 아마 1~2년 정도 지나서는 Notebook에서 Lab 환경으로 이행할 것으로 보인다.
* [JupyterLab 레포지토리](https://github.com/jupyterlab/jupyterlab)
* 개인적으로 사용해 보니 확실히 Notebook 보다 더 편리하고 기능이 더 많다.
* conda-forge 패키지 저장소에서도 제공하고 있기 때문에 설치 방법은 간단하다.

```
conda install -c conda-forge jupyterlab
```

* 설치 후, 다음 명령으로 실행한다.

```
julia lab
```

* 그러면 주소는 다음과 같이 나온다.

```
http://localhost:8888/lab
```

* 기존의 Notebook 환경이 그립다면 주소를 이렇게 바꾸면 된다.

```
http://localhost:8888/tree
```

* 아마 당분간은 이렇게 Lab과 Notebook을 공존시키다가, Lab이 충분히 성숙되면 Notebook은 별도로 떨어뜨리기로 계획되어 있다고 한다.


# 결론
* 이제 Jupyter에서 Python, C, Octave, Julia, Bash 등을 마음대로 사용할 수 있게 되었으니 가지고 놀면 된다.





