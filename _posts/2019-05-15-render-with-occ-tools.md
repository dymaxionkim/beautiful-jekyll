---
layout: post
published: true
title: Render_with_OCC_Tools
subtitle: 'OpenCascade에서 제공하는 Viewer, Renderer'
date: '2019-05-15'
bigimg: /img/bigimg47.jpg
image: >-
  https://www.opencascade.com/sites/default/files/OPENCASCADE_Logo_RGB_transparent_4.png
tags: software
---
# OpenCascade에서 제공하는 Viewer, Renderer

## 개요

* [OpenCascade](https://www.opencascade.com/)에서 오픈소스로 제공하는 OCC툴킷은, 오픈소스 진영에서 사용가능한 거의 유일한 BRep 커널이기 때문에, CAD 관련한 오픈소스 툴들은 전부 이것을 사용하고 있다고 봐도 무방할 것이다.
* 예외적으로 OCC를 사용하지 않는 경우는 BRep이 아니고 Mesh 데이타 구조체를 사용하는 경우 뿐이다.
* 원래 이 회사는, 80년대에 유클리드라는 CAD 제품을 개발해서 사업을 하다가, 기존의 메이저업체들에게 도전하기에 너무 버거웠던 나머지(?) 사업모델을 완전히 바꾸었던 역사가 있다.  즉 유클리드 CAD 제품은 폐기하고, 이것을 개발하면서 만들었던 CAD커널을 OpenCascade라는 이름으로 바꾸고 오픈소스화한 것이다.  전형적인 오픈소스 사업모델에 맞도록 소스코드는 개방한 대신, 이것을 사용하려는 개발자들을 가르치는 교육사업 및 기술지원 사업을 통해서 수익을 얻는 방식으로 바꾸었고, 현재까지 생존에 성공했다고 볼 수 있다.
* 대표적인 예로, 우리나라에서 성공한 CAE 솔루션으로 인정받고 있는 Midas의 유한요소해석 소프트웨어도, 초기에는 OCC 커널을 사용했었다고 한다.  나중에 프로그램 규모가 커지고 완성도를 올리기 위해 Parasolid커널로 바꾸기는 했지만.
* 아무튼 이와 같이, 스타트업 단계에 있는 업체나 오픈소스 개발자들에게는 가용한 유일한 CAD커널이기 때문에, 틈새시장 측면에서 OCC는 굉장히 중요한 기반기술이라고 생각된다. (물론 퀄리티는 Parasolid 같은 대규모 코드와는 직접 비교하기 힘든 것 같다.)
* 아무튼, OCC에서 기술지원사업을 수행하기 위해 여러가지 솔루션을 만들어서 유료 또는 무료로 제공을 하고 있는데, 그 중에 2가지 무료 툴을 사용해서 유용한 결과물을 얻을 수 있다고 생각된다.
* [CAD Assistant (3D 뷰어)](https://www.opencascade.com/content/cad-assistant) 및 [CADRays (렌더러)](https://www.opencascade.com/content/cadrays)가 그것이다.
* 다운로드는 [OpenCascade](https://www.opencascade.com/) 홈페이지에 회원가입해서 계정을 만들어 로그인한 다음, 해당 제품 페이지에서 다운로드 링크를 찾아 받으면 된다.  둘 다 기본적으로 zip 압축 패키지로 제공되므로, 별도 설치 없이 압축만 풀고 그 안의 실행파일만 더블클릭하면 실행이 된다.
* 다만 불행히도 리눅스 버전은 제공되지 않는다.

## CAD Assistant

### 핵심 특징

* STEP,IGES 파일을 직접 읽을 수 있다.  물론 각종 Mesh 파일들도 읽는데 문제가 없다. 아울러 다양한 포멧으로 변환해서 저장하는 것도 가능하다.  즉 이것을 이용해서 포멧을 변환하는 툴로도 활용할 수 있다.
* 파일을 읽어들인 후에, 화면에서의 움직임이 상당히 날렵하다.  상당히 큰 어셈블리를 읽어들여도 장애없이 매우 빠르게 돌려볼 수 있다.
* 분해, 단면보기 정도는 기본적으로 잘 된다.

![](https://www.opencascade.com/sites/default/files/934_cad-assistant-for-android-showing-2.png)


## CADRays

### 핵심특징

* STEP 파일을 직접 읽어들일 수 있다.  다만 완벽하지는 않아서, 어셈블리를 읽어들이면 모든 색상정보는 날아가고, 어셈블리 구조도 한덩어리로 들어오기 때문에 하나씩 다 수동으로 깨줘야 한다.
* 하지만 obj 같은 Mesh 포멧의 경우에는 어셈블리 및 색상정보들이 문제없이 잘 읽어들여진다.
* UI가 상당히 간단하다.  때문에 반나절 정도만 이리저리 해 보다 보면, 별다른 설명서를 읽지 않아도 대충 사용법을 알 수 있다.
* AMD, NVIDIA, INTEL 그래픽 가속을 기본적으로 지원한다.  (그래픽 가속기가 없는 컴퓨터에서는 제대로 돌아가는지 확인을 못해봤다.)
* 노이즈를 점점 줄여가는 사이클 렌더링 방식이다.  때문에 실시간으로 렌더링 상태를 보면서 조건을 맞추기가 좋다.  다만 그래픽 가속기 성능이 상당히 좋은 것을 사용하지 않으면 FPS가 3~7 정도로 엄청 떨어지게 되므로 굉장히 버벅대는 것을 느낄 수 있다.  (이 경우에는 OpenGL 쉐이딩 상태로 해 놓고 구도를 맞추던가 하는 식으로 약간 번거롭게 작업해야 한다.)
* 재질을 설정한다던가, 배경 그림을 맞춘다던가 하는 기본적인 툴은 갖춰져 있지만, 커스텀으로 세밀하게 여러 조건을 맞춰주려면 어느정도의 추가 작업이 필요해진다(Keyshot 보다 살짝 더 번거로운 정도).

### 사용방법

<html>
<iframe width="560" height="315" src="https://www.youtube.com/embed/D6_uGxmhuVk" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
</html>

<html>
<iframe width="560" height="315" src="https://www.youtube.com/embed/eu_dMMQAhd0" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
</html>



## 워크플로우

* STEP 파일로 만든 완제품 설계데이타가 있다고 하자.
* 그럼 우선 CAD Assistant로 이것을 불러들여서, 각 파트마다 색상을 주거나 하는 등의 작업을 살짝 해 준다.  (물론 색상 작업은 CAD 모델러에서 먼저 한 다음에 STEP 파일을 만들어도 무방하다.)
* 이 파일을 obj 포멧으로 Export해서 저장해 준다.  그러면 obj 파일과, 색상 정보를 담은 mlt 파일이 함께 만들어진다.
* 이제 CADRays를 실행시키고, obj 파일을 Import해 준다.
* 그리고 렌더링을 하면 된다.


### 사용해본 소감

* 무료 렌더링 전용 툴 중에서는 가장 사용성이 좋아 보인다.  학습곡선이 거의 없다시피하다.
* 경쟁자 포지션으로는 [Kerkythea](http://www.kerkythea.net/cms/) 정도를 생각해 볼 수 있는데, 이것보다 훨씬 더 쉽다고 생각하면 될 것 같다.  물론 기능 자체는 이것보다 더 심플하다. (애니메이션이 안된다는 것 등)
* CAD Assistant는 상당히 안정적으로 동작한다.  그러나 CADRays는 대규모 파일을 불러들이면 GPU 부하가 상당히 많이 걸려서 좀 버벅대는 편이다. 부하가 많이 걸리면 그냥 비정상종료되는 경우도 있다.  (그래픽카드는 일단 고성능을 쓰는 것이 좋겠다.)
* 만일 그래픽카드 성능이 좋지 않은 컴퓨터를 사용한다면, CADRays 대신 Blender에서 Cycles 렌더러로 멀티코어 CPU로 설정해서 이용하는 편이 낫다고 생각된다.
