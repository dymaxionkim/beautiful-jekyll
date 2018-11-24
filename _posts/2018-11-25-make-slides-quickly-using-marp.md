---
layout: post
published: true
title: Make slides quickly using Marp
date: '2018-11-22'
subtitle: 마크다운 가지고 슬라이드를 가장 신속하게 만들기
bigimg: /img/bigimg44.jpg
image: 'https://raw.githubusercontent.com/yhatt/marp/master/images/marp.png'
tags: software
---
* 마크다운 가지고 슬라이드 만드는 도구들이 수없이 많이 나왔는데, 그중에 솔직히 마음에 드는게 거의 없었다.
* Reveal.js의 경우에는, 직접 html를 편집한다는게 보통 골치아픈게 아니었고, 중간에 마크다운 삽입이 가능하다고는 하지만 워크플로우 자체가 너무 복잡하기 때문에 생산성이 올라갈 수가 없었다.
* Pandoc에 Reveal을 연결해서 마크다운 문서를 html로 변환하는 것은 결과물이 어떻게 튀어나올지 예측이 안되고, 대체로 엉망으로 나오기 때문에 역시 아웃.
* Jupyter Notebook에서 마크다운 슬라이드를 만드는 것은, 작성환경이 나쁘지는 않으나 .ipynb 포멧으로 인해 배포에 문제가 생긴다.
* 기타 상업화된 도구들은 완성도가 높은 것들도 있긴 하지만, 상업화된 것들이기 때문에 배제.
* 이런 저런 이유로 다 배제하고 최종적으로 남은 것이 Marp이다.

## Marp

* 홈페이지 : https://yhatt.github.io/marp/
* 저장소 : https://github.com/yhatt/marp
* 그냥 다운로드 받아서 압축 풀고 그 안의 실행파일 실행시키면 바로 뜬다.
* 그리고 마크다운으로 줄줄 써 주면 실시간으로 슬라이드를 볼 수 있다.
* Marp에서 자체적으로 약간 변형한 문법을 첨가해 주면 간단하게 이미지 크기조절 같은 것이 이루어져, 이미지 삽입시 매우 편리하다.
* pdf 출력이 자체적으로 된다.
* html 출력이 안된다.  이거 하나가 약간 불만이다.  Reveal하고 엮어서 출력되도록 해 주면 완벽할 것 같다.

![2018-11-25-002631_1239x759_scrot](https://user-images.githubusercontent.com/12775748/48969922-e7149f00-f048-11e8-9816-55d76a3c4e1a.png)
