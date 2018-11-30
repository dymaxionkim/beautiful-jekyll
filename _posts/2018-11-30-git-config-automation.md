---
layout: post
published: true
title: git config automation
date: '2018-11-30'
bigimg: /img/bigimg46.jpg
image: 'https://git-scm.com/images/logos/downloads/Git-Icon-1788C.png'
tags: software
subtitle: My git config automation
---
## 나의 git 환경을 한 방에 설정하기

* git을 처음 설치하고 난 직후에 글로벌 환경설정을 자동으로 수행하기 위한 쉘스크립트 파일이다.
* Ubuntu 16.04, 18.04에서 적용해서 문제가 없었다.
* 먼저 다음 작업을 수행해 준다.

```bash
sudo apt install ghostscript imagemagick gpicview catdoc odt2txt diffpdf libreoffice
mkdir ~/git
cd ~/git
git init
git config --global user.email 이메일주소
git config --global user.name 이름
git config --global color.ui auto
git config --global core.editor nano
git config --global credential.helper cache
git config --global push.default matching
cd ~
```

* 아래와 같은 코드를 `git-config` 파일로 저장한 후, 딱 한 번 실행시키면 된다.

```bash
#!/bin/bash

##########################################################################
# Config my Git
# svg, png, jpg, gif, pdf, docx, odt, ods, odp
# by Dymaxion.Kim@gmail.com
# 20181130 : 1st version for Ubuntu 18.04
##########################################################################

# Make Directory for Scripts
mkdir -p ~/.config/git/ext

# office2pdf Script
OFFICE=${HOME}/.config/git/ext/office2pdf
echo '#!/bin/bash' > ${OFFICE}
echo 'for FILE in `ls $1`; do' >> ${OFFICE}
echo '  if [ ${FILE##*.} = "docx" ]; then' >> ${OFFICE}
echo '    echo "$FILE"' >> ${OFFICE}
echo '    soffice --headless --convert-to pdf $FILE' >> ${OFFICE}
echo '  fi' >> ${OFFICE}
echo '  if [ ${FILE##*.} = "pptx" ]; then' >> ${OFFICE}
echo '    echo "$FILE"' >> ${OFFICE}
echo '    soffice --headless --convert-to pdf $FILE' >> ${OFFICE}
echo '  fi' >> ${OFFICE}
echo '  if [ ${FILE##*.} = "odt" ]; then' >> ${OFFICE}
echo '    echo "$FILE"' >> ${OFFICE}
echo '    soffice --headless --convert-to pdf $FILE' >> ${OFFICE}
echo '  fi' >> ${OFFICE}
echo '  if [ ${FILE##*.} = "odp" ]; then' >> ${OFFICE}
echo '    echo "$FILE"' >> ${OFFICE}
echo '    soffice --headless --convert-to pdf $FILE' >> ${OFFICE}
echo '  fi' >> ${OFFICE}
echo 'done' >> ${OFFICE}
echo '' >> ${OFFICE}
chmod +x ${OFFICE}

# Execute Once
BASHRC=${HOME}/.bashrc
echo '# office2pdf' >> ${BASHRC}
echo 'export PATH="~/.config/git/ext:$PATH"' >> ${BASHRC}
echo '' >> ${BASHRC}

# Diff Images Script
IMAGE=${HOME}/.config/git/ext/diffimg
echo '#!/bin/bash' > ${IMAGE}
echo '# Diff Images (svg,png,jpg,gif)' >> ${IMAGE}
echo 'compare -verbose -fuzz 3% $2 $1 png:- | montage -geometry +4+4 $2 - $1 png:- | display -antialias -title "$1" -' >> ${IMAGE}
echo '' >> ${IMAGE}
chmod +x ${IMAGE}

## ~/.gitconfig
git config --global core.attributesfile ~/.config/git/gitattributes
git config --global diff.word.textconv catdoc
git config --global diff.odf.textconv odt2txt
git config --global diff.diffimg.command ${HOME}/.config/git/ext/diffimg
git config --global diff.diffpdf.command diffpdf
git config --global alias.diffimg 'difftool -y -t diffimg'
#git config --global alias.diffpdf 'difftool -y -t diffpdf'

## ~/.gitattributes
ATTR=${HOME}/.config/git/gitattributes
echo '## Diff Extensions' > ${ATTR}
echo '*.docx diff=word' >> ${ATTR}
echo '*.ods diff=odf' >> ${ATTR}
echo '*.odt diff=odf' >> ${ATTR}
echo '*.odp diff=odf' >> ${ATTR}
echo '*.svg diff=images' >> ${ATTR}
echo '*.png diff=images' >> ${ATTR}
echo '*.jpg diff=images' >> ${ATTR}
echo '*.jpeg diff=images' >> ${ATTR}
echo '*.gif diff=images' >> ${ATTR}
echo '*.pdf diff=pdf' >> ${ATTR}
echo '' >> ${ATTR}

echo "Finished !"
exit 0

```


## 사용방법

* 작업중인 git 저장소 디렉토리 안에서, pdf 파일 등을 변경하고 난 후, `git add` 하기 전에 다음 명령을 준다.

```bash
git diff
```

* 그러면 diff 결과를 볼 수 있다.
* 이미지 파일(png,jpeg,jpeg,gif) 파일의 경우에는 변경하고 나서 `git add` 하기 전에 다음 명령을 준다.

```bash
git diffimg
```

## 기타 함께 활용 가능한 유틸리티

* `diffpdf` : GUI로 diff PDF.  아무데서나 명령을 치면 된다.
* `office2pdf` : TUI로 오피스파일(docx,pptx,odt,odp)을 pdf로 일괄 변환한다.  작업중인 디렉토리 내에서 명령을 치면 된다.
