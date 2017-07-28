---
layout: post
published: true
title: CAE_Compare
subtitle: >-
  Comparing for Open-Source CAE Softwares : CalculiX, Code_Aster, Elmer, Z88
  Aurora
date: '2017-07-28'
bigimg: /img/bigimg36.jpg
image: >-
  https://cloud.githubusercontent.com/assets/12775748/19234778/ce063ea2-8f28-11e6-918f-5ae7e372149f.png
tags: mechanics
---
## 개요
* 4가지 소프트웨어를 가지고 비슷한 해석을 실시해 본다.
* 가장 간단한 형상으로 해 본다.
* 각각의 특징과 장단점을 파악해 본다.

|번호|해석자|전/후처리 소프트웨어|
|----|----|----|
|1|CalculiX ccx|Salome-meca, CalculiX Launcher, cgx|
|2|Code_aster|Salome-meca|
|3|Elmer|Salome-meca, ElmerGUI, Paraview|
|4|Z88|Z88AuroraV3|

* 해석데이타 : [깃허브링크](https://github.com/dymaxionkim/ElmerFEM_Examples/tree/master/20161012_Test_Compare)

## 1. CalculiX

<iframe width="560" height="315" src="https://www.youtube.com/embed/WXPP0lmmdIU" frameborder="0" allowfullscreen></iframe>

* Salome-meca에서 매쉬생성 몇 경계면 그룹화 작업 실시.  `.unv` 파일 생성.
* CaculiXLauncher에 포함된 'unical Converter' 유틸리티를 사용하여 `.unv` 파일을 CalculiX용 `.inp` 파일로 변환.
* CaculiXLauncher의 'CCX WIZARD!'를 이용하여 해석조건을 GUI로 설정.  CalculiX용 `.inp` 파일로 생성.
* CaculiXLauncher 상에서 `ccx`로 해석 계산 실시.
* 해석결과는 `.frd` 파일로 저장된다.
* 해석 완료후 CaculiXLauncher 상에서 `cgx`를 띄워 결과를 봄.
> CalculiX의 ".inp" 파일은 Abaqus용 ".inp" 파일을 흉내내어 규칙이 만들어져 있으므로 많은 부분이 유사하다.  다만 서로 호환될 정도로 동일하지는 않다.  ".inp" 파일 하나에 매쉬형상정보,그룹정보,해석조건 등 모든 정보를 다 포함할 수 있으나, 너무 파일이 지저분해지기 때문에 여러개로 분할할 수도 있다.  CalculiXLauncher의 "CCX WIZARD!"는 여러개의 ".inp" 파일로 분할해서 생성하도록 되어 있다.

* ccx 해석자의 특징은, 내부적으로 Arpack 라이브러리를 사용한다는 점 같다.  Direct Solver이므로, 계산시 RAM(메모리)를 많이 사용한다.  특히 CPU를 멀티코어로 지정해 뒀을 경우에는 메모리 점유율이 더 커지기 때문에, 어느정도 규모가 되는(10만개 이상의 노드 수준) 해석시에는 시스템에 메모리가 충분한지 먼저 따져볼 필요가 있다.
* 그리고 기본적인 Direct Solver이다 보니, 매쉬가 좀 복잡하거나 비정형성이 높을 경우 계산 실패 확률도 있는 것 같다.  수렴성 문제다.  형상정의, 매쉬 생성할 때 특성을 잘 파악해서 주의깊게 가급적 단순하게 구성할 필요가 있어 보인다.


## 2. Code_aster

<iframe width="560" height="315" src="https://www.youtube.com/embed/TvFtSnOSsXg" frameborder="0" allowfullscreen></iframe>

* Salome-meca에서 전처리작업한 자료는 `.hdf` 파일로 저장된다.  형상정보,매쉬정보,그룹정보가 여기에 들어가며, 나중에 다시 열어서 재편집 등이 가능하다.
* Salome-meca 내부의 Aster 툴킷 안에는 크게 ASTK, Eficas 및 간단한 Wizard 4개(Linear elastic, Modal analysis, Linear thermic, Crack analysis)가 있다.
* 이 중에서 ASTK는 Code_aster 솔버의 해석을 하기 쉽도록 도와주는 작업관리 GUI툴이다.  계산할 때 CPU코어 등 컴퓨팅 자원을 어떻게 할당해 줄지, 매쉬 생성해서 해석기와 연결해 주는 방법, 해석후 후처리로 데이타를 그래프로 띄워주는 등.  텍스트로 직접 코딩해서 작성하는 대신 항목별로 버튼 눌러가면서 숫자 쉽게 작성 해 주는 것이다.  Salome가 없을 경우에 필요해서 Code_aster 팀에서 직접 만든 것 같다.  따라서 Salome와 기능적으로 중복되는 부분이 많다.  작성이 다 되면 `.astk` 파일로 저장된다.  단, 여기서는 이 툴은 사용하지 않는다. (설정파일 소스레벨에서 직접 매니악하게 다룰 때 필요할 수 있고, 특히 병렬연산을 수행할 때 필요하다.)
* Eficas는 실제 Code_aster가 읽어들일 해석조건 설정파일인 `.comm` 파일을 쉽게 작성하도록 도와주는 GUI툴이다. (사실 큰 도움은 안 된다.  파라미터 변수명칭들이 전부 프랑스어 기반이라서 직관적으로 이해하기가 상당히 어렵다.)  각종 해석조건을 부여하기 위한 파라미터들을 마우스로 선택해서 지정해주는 등의 일을 상대적으로 편하게 할 수 있다.  물론 각 파라미터들의 의미는 Code_aster 매뉴얼을 펴놓고 뒤져가면서 하나하나 맞춰줘야 한다.  복잡한 해석을 실시할 때는 이거라도 있으면 큰 도움이 될 것이다.  `.comm` 파일을 텍스트에디터만 달랑 열어놓고 줄줄 쓸 수는 없기 때문이다.  다만 역시 여기서는 Eficas는 사용하지 않았다.  일반적으로는, Wizard를 이용해서 기본적인 `.comm` 파일의 기본 틀을 생성한 후에, Eficas를 이용하여 그것을 수정보완하는 방식으로 진행하는 것 같다.
* Eficas도 어려운 초보자를 위해, 4가지의 Wizard 버튼이 있다.  Linear elastic, Modal analysis, Linear thermic, Crack analysis(XFEM)가 그것이다.  이들 해석 케이스의 경우에는 Eficas 없이 Wizard로 신속하고 쉽게 조건을 부여해서 해석할 수 있다.  다만 이 범위를 벗어나는 고급 해석을 위한 추가적인 Wizard는 아직 없다.
* 여기서는 Linear elastic Wizard를 사용하여 해석조건을 잡아주었다.  이것의 단점은, 경계조건 부여할 때 Pressure만 입력 가능하고 Force는 입력하는 기능이 없다!!!! 헐.  때문에 Force를 주고 싶으면 Pressure로 환산해서 넣어줘야 한다.  그리고 Pressure이다 보니 당연히 Force Direction도 마음대로 못 주고, +/- 방향으로만 줄 수 있을 뿐이다.  (즉 디리클레 바운더리 컨디션은 못 주고, 노이만 바운더리 컨디션만 줄 수 있도록 만들어져 있다.  디리클레 바운더리 컨디션 등 다른 조건으로 바꾸려면 Eficas 또는 텍스트 편집기를 이용하여 직접 `.comm` 파일을 수정해 줘야 한다.)
* 해석을 실시하는데, Code_aster를 돌려보니 다른 툴보다 크게 차이나는 점은, 계산 도중 임시로 할당하는 하드디스크 사용량이 많다는 것이다.  따라서 좀 큰 모델을 계산시킬 떄는 하드디스크 용량을 가급적 많이 남겨둬야 할 것 같다.
* 해석 도중 메모리 사용량은 CaluliX와 비슷하거나 살짝 더 작은 것 같다.
* 해석 결과는 `.rmed` 파일로 저장된다.  이 포멧은 내부적으로 VTK를 준수하므로, Salome-meca에 내장된 ParaVis를 통해 열어 볼 수 있다. (ParaVis는 Paraview를 그냥 통째로 Salome-meca 안에 집어넣은 것이다)


## 3. Elmer

<iframe width="560" height="315" src="https://www.youtube.com/embed/yjwxx6d1I3c" frameborder="0" allowfullscreen></iframe>

* ElmerGUI상에서 직접 `.unv`파일을 불러들이면 신속하게 모델이 띄워진다.
* Salome-meca에서 정의한 경계면 그룹들은 대체로 이상없이 잘 들어온다.  다만 경우에 따라 무시되는 경우도 있는 것 같다.  무시되는 조건은 특정하기 어렵다.  이때는 ElmerGUI 상에서 면분할 등의 작업을 추가로 더 해 줄 필요가 있다.
* 또한, 정의된 그룹들의 이름은 ElmerGUI에서는 전부 다 무시되고 임의로 부여된 숫자이름으로 치환된다.  (대신 ElmerGUI 말고, 터미널상에서 ElmerGRID로 직접 매쉬를 읽어서 Elmer용으로 변환할 경우에는 그룹 이름들이 보존된다고 한다.)  이후 ElmerGUI 상에서 해석조건들을 설정해 준다.  ElmerGUI의 역할은, 앞서 Code_aster에서 Eficas가 하는 일과 비슷하다.  Elmer에서의 해석설정파일은 `.sif`로 만들어진다.
* Elmer에서 제공하는 솔버는 몇가지 다양한 연산 라이브러리를 사용자가 마음대로 선택할 수 있게 되어 있다.  기본 셋팅은 Iterative Method인 BiCGStab으로 되어 있고, 수렴공차는 1e-10으로 지정되어 있다.  Iterative Method는 메모리 사용량도 적어서 백그라운드로 계산시키기에 좋다.  컴퓨터가 뻗어버릴 확률이 거의 없다.  대신 수렴근사화를 반복적으로 하다 보니, 해답을 찾아내는데 들어가는 시간은 Direct Method에 비해 엄청나게 더 길어질 수 있다.
* 경험적으로 볼 때, 본 케이스에서 적용하는 Linear Elasticity Equation의 경우에는 Iterative Method가 적합한 것 같다.  CalculiX, Code_aster에서 모두 실패한 조건이라도 여기서는 시간은 비록 오래 걸릴지언정 훨씬 더 높은 확률로 수렴에 성공한다.
* 대신 Modal Analysis를 할 때는, Direct Method가 더 적합하다.  상당히 신속하게 답을 찾아낸다.  Iterative Method를 적용하면 거의 무한정 계산시간이 길어질 수도 있다.
* Direct Method는 배포판 기준 Banded 및 Umfpack이 제공된다.  개인적으로는 Umfpack를 주로 사용한다.  추가적으로 더 효율적인 분산 멀티코어 대응 MUMPS도 가능은 하나, 이것을 적용하려면 Elmer 패키지 자체를 MUMPS 포함하도록 옵션을 주고 직접 빌드해야한다.  PC 수준에서는 Umfpack이 필요한 수준을 충분히 만족해 준다.
* Elmer의 자체 결과파일 포멧은 `.ep`이다.  그러나 이것 말고 `.vtu`로 저장하도록 바꿔주었다.  이렇게 하면 Paraview에서 직접 읽어서 후처리 가능하다.
* Elmer의 강점은, Multi-physics가 상당히 넓은 범위로 커버된다는 점이다.  물론 각각의 Equations들이 각각의 전문 상용 소프트웨어들보다는 뒤떨어지지만, 전체적으로 놓고 보면 상당히 강력하다는 것이다.  또한, 굉장히 유연하다.  모든 부분에서 세부설정이 가장 용이하며, 필요할 경우 MATC 및 Fortran을 이용하여 커스터마이징에 매우 잘 대응된다.
* 다만 구조해석 부분에서, 접촉해석 기능은 아직 매우 미약하다.  (일반적인 구조해석툴에서 사용하는 Penalty,Lagrange등의 접촉방정식 말고 다른 방정식인 것 같다.  수렴실패 확률도 높고, 이를 잡아내기 위한 파라미터 수정 방법도 아직 전혀 감을 잡지 못했다.)
* 또한 Explicit 해석 기능은 포함되어 있지 않다.  MultiBody를 다루기 위해서는 Salome-meca가 반드시 필요하다. 등등...


## 4. Z88

![004](https://cloud.githubusercontent.com/assets/12775748/19336820/7bdd5e26-9149-11e6-9f53-bee3ca9b39b5.png)

* 앞서 다루었던 CalculiX, Code_aster, Elmer의 핵심 해석자는 모두 포트란으로 개발된 것들이다.  그러나 Z88은 C++로 개발되었다.  때문에 특성이 많이 다른 것 같다.
* 또한 Z88Aurora GUI 환경은, VTK 표준을 별로 고려하지 않았다.  때문에 결과를 Paraview에서 보기는 힘들다.
* 대신, 매쉬데이타를 직접 읽어들일 때는 `.dxf`가 지원된다.  (Nastran, Ansys등 상용 포멧도 읽을 수 있도록 되어 있는데 이건 나에게는 별로 쓸모가 없다.)
* 전처리 작업 방식도 상당히 독특하다.  SPIDER라는 리모콘 팝업이 있는데 이것을 이용하여 순서대로 따라가면 정형적으로 작업하기가 쉽다.
* 그래픽이 조금 무거운 편이다.  때문에 VirtualBox 가상머신에서 많은 노드로 쪼개진 매쉬를 띄우면 작업하기 곤란할 정도로 버벅댄다.
* 그리고 어차피 노드가 엄청 많아지면 다른 곳에서도 에러를 내뿜기 시작하기 때문에 (메모리 부족, 이유없이 다운 등등) 대규모 모델을 해석하기에는 적합하지 않다.
* 병렬연산 등에 대한 지원도 PC 수준까지만 된다.  대신 GPU를 사용한 병렬연산을 지원하기 위해 추가 개발이 진행되고 있는 것 같다.
* 내장된 해석자가 몇 가지 있는데, 제일 좋은 것은 역시 Pardiso이다.  이것은 Sparse Matrix(희소행렬) 연산기이기 때문에, 계산 효율이 극적으로 좋아진다.  체감상 앞서 다룬 다른 툴들에 비해서, 같은 조건이라면 계산속도 하나 만큼은 제일 빠른 것 같다. (물론 수렴에 성공할 경우의 이야기다)
* 이런 희소행렬 연산기를 쓰는 솔버라면, 당연히 형상복잡성은 낮추고 노드개수는 메모리 허용하는 범위 안에 있다면 그 장점이 극대화될 것이다.
* 상대적으로 간단한 형상을 최대한 신속하게 계산해 볼 떄 유용할 것 같다.
* 기능적인 측면에서 다른 툴에 없는 독자성은 아직 크게 없어 보인다.
* 툴 자체 특성으로, 독특한 편의기능이 몇가지 있다.
* 대표적으로 1D로 구성한 트러스 구조물을 `.dxf` 파일로 읽어들인 후, 해석조건 설정할 때 빔(Beam)의 단면 형상을 골라줄 수 있다.  원형봉,사각형봉,사각관 이런 식으로 골라서 치수를 입력해 주면, 해당 빔의 관성모멘트값을 부여해서 계산해 준다.  복잡한 트러스 구조물을 다룰 때, 형상을 간단하게 넣어서 신속하게 결과를 얻어내기 좋을 것 같다.  무식하게 트러스를 일일이 모델링해서 대형 구조물을 구성하게 되면, 계산량이 엄청 많아지고 수렴실패 확률도 매우 높아지기 때문이다.

## 결론
* 살펴본 4가지 소프트웨어 모두 나름의 장점을 가지고 있는 것 같다.
* 각 툴의 특성을 정확히 알고 용도에 맞게 사용한다면 만족도를 더 올릴 수 있을 것이다.
  - CalculiX : 멀티바디 단순접촉 및 비선형해석에 적합
  - Code_aster : 크랙현상 해석, 엄밀한 접촉모델에 적합
  - Elmer : 다중물리학, 싱글바디, 대규모 모델에 적합
  - Z88 : 초보학습용, 간단한 모델의 신속해석, 싱글바디에 적합
* 아마 나는 Elmer를 주력으로 하고, CalculiX로 보완하며, 시간을 두고 Code_aster를 사용하게 될 것 같다.  Z88은 잘 손이 가지 않는다.

