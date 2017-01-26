---
layout: post
published: true
title: MarkdownSlides
subtitle: "Markdown 문서를 Reveal 등으로 자동 변환해 주는 툴"
date: '2017-01-26'
bigimg: /img/bigimg26.jpg
image: >-
  https://cloud.githubusercontent.com/assets/12775748/22331775/94703f16-e410-11e6-9bdc-53c801f470e4.png
tags: software
---


# Markdown Slides?

![markdown-syntax-language](https://cloud.githubusercontent.com/assets/12775748/22331775/94703f16-e410-11e6-9bdc-53c801f470e4.png)


## 용도

- 저장소 : <https://github.com/asanzdiego/markdownslides>
- 별다른 조치를 취하지 않은 평범한 마크다운 문서를, 한 방에 자동으로 다음과 같은 여러가지 포멧으로 변환해 주는 툴이다.
- 마크다운 기반의 블로그 또는 위키에서 작성한 문서를 보고서나 프리젠테이션 슬라이드로 간단하고 깨끗하게 변환해 주기 때문에 시간 절약을 위해 필요한 것 같다.


## 얻어낼 수 있는 결과물 (1)

_변환해 주는 포멧은 다음과 같다.  모두 한꺼번에 해 주기 때문에 별다른 신경을 쓸 필요가 없다._

- __docx__ : MS Word 포멧으로 나온다.  Pandoc이 설치되어 있지 않으면 변환을 포기한다.
- __html__ : 단순히 html 포멧으로 나온다.
- __odt__ : 오픈 도큐먼트 포멧으로 나온다.  Libre Office 등에서 다루기에 적합하다.

## 얻어낼 수 있는 결과물 (2)

- __deck-slides.html__ : 로컬 Deck.js를 사용하는 슬라이드 html 파일로, 기본 Sky 테마로 나온다.
- __deck-dlides-alternative.html__ : 로컬 Deck.js를 사용하는 슬라이드 html 파일로, swiss 테마로 나온다.

## 얻어낼 수 있는 결과물 (3)

- __reveal-online-slides.html__ : 온라인상의 Reveal.js를 사용하는 슬라이드 html 파일로 나온다.  슬라이드 자체적으로 테마 등을 변경할 수 있는 메뉴도 포함되어 있다.
- __reveal-slides.html__ : 로컬 Reveal.js를 사용하는 슬라이드 html 파일로 나온다.  슬라이드 자체적으로 테마 등을 변경할 수 있는 메뉴도 포함되어 있다.  디폴트 기본 테마로 나온다.
- __reveal-slides-alternative.html__ : 로컬 Reveal.js를 사용하는 슬라이드 html 파일로 나온다.  슬라이드 자체적으로 테마 등을 변경할 수 있는 메뉴도 포함되어 있다.  기본은 밝은 테마로 나온다.

## 얻어낼 수 있는 결과물 (4)

- __to-book.md__ : 출판용 마크다운으로 정리되어 나온다.
- __to-slides.md__ : 슬라이드용 마크다운으로 정리되어 나온다.
- __pdf__ : Reveal 슬라이드는 자동으로 pdf로도 나온다.  다만 TeX 및 Pandoc 환경이 제대로 되어 있지 못하면 생성에 실패한다.


# 설치 순서

## TeX 설치

- Pandoc이 pdf 파일을 생성할 때 필요하다.
- TeXlive 패키지 한 방으로 해결되니 세상이 좋아졌다.  다만 여러 언어팩들이 전부 싹 다 들어있기 때문에 용량이 너무 커서 좀 압박이 있다(2GB 이상).

```
sudo apt-get install texlive-full
```


## Pandoc 설치

- 참고 : https://anaconda.org/conda-forge/pandoc
- 마크다운 문서를 docx, odt, pdf 등의 포멧으로 자동 변환해 준다.
- 현재 Anaconda Python 환경이기 때문에 conda 패키지 관리자로 설치한다.

```
conda install -c conda-forge pandoc
```


## PhantomJS 설치 (1)

- 독점 소프트웨어라서 따로 설치해 줘야 하는 것 같다.
- 하는 일은 Headless Website Testing, Screen Capture, Page Automation 등이라고 하는데 아무튼 꼭 필요한 것 같다.
- 일단 [여기](http://phantomjs.org/download.html)서 다운로드 받고 압축을 푼다.

```
cd ~
wget https://bitbucket.org/ariya/phantomjs/downloads/phantomjs-2.1.1-linux-x86_64.tar.bz2
tar xvfj ./phantomjs-2.1.1-linux-x86_64.tar.bz2
rm ./phantomjs-2.1.1-linux-x86_64.tar.bz2
```

## PhantomJS 설치 (2)

- 이제 pantomjs 명령이 어떤 곳에서도 먹히도록 경로를 잡아주어야 한다.  `~/.bashrc` 파일을 편집기로 열어서 마지막 부분에 아래 내용을 덧붙인 후 저장하고, 터미널을 재기동 한다.

```
# Phantomjs
export PATH="/home/dong/phantomjs-2.1.1-linux-x86_64/bin:$PATH"
```


## MarkdownSlides 설치

- [깃허브 저장소](https://github.com/asanzdiego/markdownslides)에서 직접 zip 파일을 받아다가 압축 해제해도 되고, 아래와 같은 git 명령으로 받아도 되겠다.

```
cd ~
git clone https://github.com/asanzdiego/markdownslides.git
```

- 이제 다 완료되었다.

# 사용법

## 마크다운 문서 준비

```
~/test/md/2017-01-26_MarkdownSlides.md
```

- 이때 조건은, 작업할 장소인 `~/test/`는 바뀌어도 되지만 그 밑에 `/md` 디렉토리는 반드시 존재해야 하고, 또 그 안에 반드시 마크다운 문서가 들어있어야 한다.


## 변환 명령

- 터미널을 열고, 장소를 이동한 후, 변환 명령을 준다.

```
cd ~/markdownslides
./build.sh max ~/test
```

- 그러면 변환 작업이 진행되고, 작업장소인 `~/test` 안에 `/export` 및 `/lib` 디렉토리가 생기면서 그 안에 파일들이 들어간다.  결과문서는 `/export` 안에 있다.


# 마크다운 유의점

## 몇가지 규칙

- 물론 아무 마크다운 문서나 다 집어넣는다고 다 예쁘게 나오지는 않으므로, 최초의 마크다운 작성시에 슬라이드 페이지 분할을 예상해서 어느정도 합리적으로 작업할 필요가 있다.

- 마크다운 문서 제일 앞머리에 다음과 같은 헤더를 넣어주면 그대로 표지가 된다.

```
% 제목
% 발표자명
% 날짜
```

- 그리고, `#`, `##`, `-`, `(빈칸4)-`으로 제목 단계를 건너뛰지 말고 반드시 준수한다.


-----

* 연습 예제 : <https://dymaxionkim.github.io/My_Slides/2017/2017-01-26_MarkdownSlides/export/2017-01-26_MarkdownSlides-reveal-online-slides.html>

<iframe src="https://dymaxionkim.github.io/My_Slides/2017/2017-01-26_MarkdownSlides/export/2017-01-26_MarkdownSlides-reveal-online-slides.html" width="640" height="480">

# 끝!



