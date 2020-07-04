---
layout: post
published: true
title: 'Trend of Mesh Generator, CAE에 관한 생각들'
subtitle: Trend of Mesh Generator
date: '2020-07-04'
bigimg: /img/bigimg51.jpg
tags: software
image: >-
  data:image/jpeg;base64,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
---
# Mesher

* 메쉬 생성 과정은 유한요소해석에서 제일 골치아픈 문제로 오랫동안 남아 있었음
* 완벽한 자동화가 어렵기도 하고, 자동화할 경우에도 에외상황이 많아 실패 확률이 높았음
* 고해상도 메쉬를 만들 경우, 메쉬 생성 자체에도 대규모 연산이 필요하게 됨
* 고해상도 메쉬로 문제를 풀 때도 대규모 연산이 필요
* 예를 들어 항공기 동체의 해석을 위한 메쉬를 만들기 위해서는 수 개월의 기간과 인력을 투입하는 경우가 보통
* 대규모 메쉬 생성을 위한 예산을 줄이기 위해 인도 등의 제3세계 엔지니어링 서비스 업체에 하청을 주는 경우도 많음
* 이런 한계점을 극복하기 위해, 메쉬 생성 분야에서도 지속적인 기술개발이 이루어지고 있음

## 주요 기법

### 1. 고대의 방식

* 손으로 절점의 좌표를 하나하나 모눈종이에 찍어서 그림
* 그 좌표를 하나하나 손으로 입력
* 컴퓨터에서 그래픽으로 표현
* 대학교 다닐때 기계공학특론 수업과제로 이걸 직접 프로그램 짜서 띄우는 것을 수행했었음.
* 그때는 이런 짓을 왜 해야 하나 싶었는데, 지금와서 생각해 보면 그 교수님을 존경하게 됨.  엄청나게 도움이 되었음.

### 2. 스크립트에 의한 자동 생성

* 대표사례 : Gmsh, ElmerGrid
* 단순한 형상일 경우에는 꽤 유용
* 파라미터 조정에 따른 개선이 용이

### 3. Import STEP

* CAD에서 모델링된 STEP 파일을 불러들여서, 그것을 가지고 메쉬를 생성하는 경우
* 실무 설계자들이 가장 원하는 방법
* STEP 파일을 읽어들여서 시현하기 위해서는 CAD커널이 필요함
* FOSS 쪽에서는 실제로 사용가능한 CAD커널은 OCC(OpenCascade)가 유일함

### 4. Netgen

* https://ngsolve.org/
* 이제 STEP 파일을 읽어들였으니, 그것을 메쉬로 변환해 줄 수 있는 메쉬 생성기 엔진이 필요
* FOSS 쪽에서는 Tetgen, Netgen, SnappyHexMesh, gmsh 등이 있음
* 가장 기본적으로 많이 사용되는 것은 Netgen
* Netgen의 결정적인 단점은 병렬연산 미지원이었는데, 최근버전에서는 지원이 되기 시작하였음
* 하지만 Netgen을 기반으로 한 Salome, Gmsh등의 2차 패키지들에는 아직 반영이 안된 상황
* 매우 클래식한 기능을 가지고 있지만, 메쉬 생성 능력이 상당히 좋고 안정적이며 완성도가 높은 편 (물론 상용 메쉬 생성기에는 못미침)
* 1D segmentation - 2D Delonay Tecellation, 3D Tecellation, Optimization 순서로 순차적인 작동을 하게 됨

### 5. 현재의 일반적인 상용 소프트웨어들

* [GiD](https://www.gidhome.com/) : 저렴하면서 FOSS로 만족하지 못하는 경우에 선택가능한 제품.  학교나 연구실에서 많이 사용.
* [Alair Hypermesh](https://www.altair.co.kr/hypermesh/) : 프로페셔널한 수준의 메쉬 생성용.  메쉬 생성기 단독 제품 중에서 가장 사용률이 높음.

### 5. Midas MeshFree

* https://kor.midasuser.com/meshfree/
* 국내 CAE 소프트웨어 업체가 만든 제품명이자 마케팅 용어
* 마케팅으로 "격자를 짤 필요가 없다"고 표현하고 있는데 이 표현은 사실 문제가 있다고 생각됨
* 메쉬를 실제로 생성을 할 필요가 없다는 것이 아니고, 메쉬 생성의 어려움을 줄여준다는 의미
* 이 방식은 가상의 Voxel 형태의 Grid Volume을 만들고, 이것을 3D Geometry와 겹친 후, 교집합 부분만 남기는 식으로 잘라주는 방식임 (경계 무격자법)
* 이후 경계면 처리는 별도의 공식으로 오류가 적게 나도록 살짝 손봐줌
* 나머지 Solver 부분은 기존의 MidasNFX 제품과 별 차이 없음
* UI 디자인도 예쁘기는 하지만 사실 별 특징이 없고 기능이 상당히 단순하게 정리되어 있음

### 6. Cubit

* 미국 국립 Sandia 연구소에서 개발 https://cubit.sandia.gov/
* Midas MeshFree의 아이디어의 원조격이 되는 메쉬생성기 (경계 무격자법)
* 구현된 수준은 Midas MeshFree보다 훨씬 더 우수함 (단순 육면체 격자 뿐만 아니라 더 복잡한 형태까지 대응)
* 미국의 단체(연구소)에서는 무료로 사용 가능.  해외에서는 무료버전 사용 불가능.
* 상업화된 버전은 coreform사에서 제, 현재는 한단계 더 나아간 신기술을 적용한 제품 출시 준비

### 7. Coreform Crunch

* https://coreform.com/
* 격자생성에서 기존의 1차 직선형 격자에서 더 나아가, 3차 Spline 곡선으로 격자 생성하는 원리
* 물론 이 경우, 솔버 측에서는 특정 지점의 물리량을 얻을 때 3차 Spline Interpolation해서 정확한 값을 얻을 수 있게 됨
* Spline 기반의 고차원 격자 생성 기법은 2000년대 들어서 기초연구가 주로 진행되었는데, 한국에서도 기본적인 이론상 가능성을 탐색한 논문 정도는 있었음
* 그런데 이걸 실제로 제품화 수준까지 구현해서 내놓은 것은 현재까지 이곳이 유일 (현재는 베타버전 단계)
* 장점은 절점의 개수를 극단적으로 현저하게 줄일 수 있어 엄청난 계산속도의 향상과 메모리 절감효과를 얻을 수 있다는 점
* 예를 들어, 기존 메쉬생성으로는 1천만개의 요소망이 필요한 해석에서, Coreform Crunch 적용시 1만개 정도로 줄일 수 있다는 것.
* 즉 1/1000로 해석규모를 줄여도 된다는 것은 엄청난 진보라고 볼 수 있음.  달리 말해 1000배 더 빠르게 결과를 얻을 수 있다는 것.
* 이와 같은 혁신 기술을 계속 추구하고 사업화할 수 있다는 것이, 바로 미국이 여전히 선두권을 유지하는 이유라고 생각됨.
* 결국 Coreform Crunch와 같은 Spline 격자생성 기술이, 향후 50년간 세계를 지배할 궁극의 기술이 될 것으로 예상함.  발전가능성이 무궁무진.

## (여담) 왜 미국인가?

* 유한요소해석 분야에서 미국은 거의 절대적인 기술적 리더쉽을 가지고 있음
* 이유는 50년대 핵폭탄 및 초음속 항공우주기술의 발전 때문
* 핵폭탄 연구를 위해 진행되었던 맨해튼 프로젝트에 참여하였던 연구원들이 로렌스리버모어, 로스알라모스, 산디아연구소 등 소위 "3대 핵무기 연구소"를 중심으로 계속 전산물리해석 연구를 진행
* 로스알라모스 연구소는 주로 에너지, 대규모 실험 등에 특화
* 로렌스리버모어는 단일 연구기관중 전세계 1위의 슈퍼컴퓨터 자원을 자체 보유
* 산디아 연구소는 단일 연구기관중 전세계 3위의 슈퍼컴퓨터 자원을 자체 보유
* 이들 핵무기 연구소들은, 연구결과물 및 소프트웨어들을 비밀로 자체개발 및 운용하다가, 시간이 많이 흐르거나 차세대 기술을 확보해서 대체 가능한 상황이 오면, 기존의 기술을 공개해서 민간시장 쪽으로 풀어주는 방식을 취함.  따라서 이들 연구소가 내놓는 결과물만 보고 그대로 따라가기만 해도 기술흐름을 놓치지 않을 수 있음.
* 핵무기 쪽 말고, 항공우주 기술을 위한 유한요소해석 분야는 주로 NASA가 주도하였음.
* NASA의 대표적인 결과물은 Nastran
* NASA 역시 Nastran을 자체적으로 개발하여 쓰다가, 시간이 많이 흐른 후에 민간에 오픈하여 상품화가 가능하게 길을 열어줌
* 미국 정부 연구소에서 이렇게 주로 주도를 했고, 민간 기업에서 자체적으로 개발한 것들은 Abaqus, Ansys, Marc 등이 있으나 미국 국립 연구소들이 가진 것들에 비하면 핵심기술 부분에서 여전히 많이 뒤떨어진다고 볼 수 있음.  이들 제품들은 사용자 환경 부분에 주로 집중하면서 범용적인 제품을 지향하거나, 특정 문제에 특화하여 니치마켓을 공략하는 쪽으로 갈라짐.
* Ansys의 경우를 보면, 웨스팅하우스 소속 엔지니어였던 스완슨 박사가 최초 코드 개발후, 회사를 설립해서 1990년대까지 스완슨 소프트웨어를 운영하다가, 결국 못견디고 금융회사에 회사를 매각하는 등의 어려움을 겪었었음.  Ansys 뿐만 아니고 다른 회사들도 대부분 이런 식으로 M&A로 이리저리 팔려다니다가 주로 대기업에 안착하는 식으로 결말을 맺게 됨.

## 신흥 세력들

* 최근에는 한국 등 신흥국가들이 저렴한 가격대의 CAE 소프트웨어 상품들을 내놓기 시작.  점차 핵심기술이 대중화되는 경향.  Daful, Midas, Recurdyn 등
* 한국이 의외로 상당히 강한 세력임
* 특히 영업력 하나만큼은 정말 기가막히게 잘한다는 생각은 듦.  Midas MeshFree 마케팅하는 거 보고 감탄했음.

* 일본산 유한요소해석 소프트웨어를 들어본 적이 있는 분? 아마 거의 없을 것임
* 일본은 이 분야에서 사실상 세력이 없음 (국가 지원 프로젝트로 만들어낸 코드나, 일본 자동차회사 등에서 자체개발한 코드가 있었지만 지금와서 물어보면 아무도 모름)

* 영국은 전통적으로 CFD에서 주목할 만한 결과물들이 있음.  StarCD, OpenFOAM
* 프랑스는 EDF Code_Aster, Code_Saturne 등 오픈소스 코드가 독보적으로 강함.  다른 유럽국가들도 오픈소스 쪽에 주로 관심을 두는 경향.
* 독일은 오픈소스 메쉬생성기,솔버를 기반으로, 웹UI를 구성해서 클라우드 SAAS 사업을 하는 벤쳐기업들이 최근에 여러 곳 나옴.

## 한국의 문제

* 오픈소스 쪽에 여전히 인식이 열악.  한국에는 개발 참여자가 거의 없음.
* 리눅스 기반 소프트웨어에 특히 무관심.  슈퍼컴,HPC 지원은 아예 생각 자체를 안한 것임.
* 관련 사업을 하는 업체들도 매출 및 생존에 목을 메는 경향이 강하다는 것
* 영업실적만 따지고 기술개발에 대해서 중요하게 생각하지 않는 여피(Yuppy) 철학이 경영자들의 머릿속을 지배한다는 점
* Ansys 위주로 돌아가는 시장 상황 (Ansys가 세계최고라고 잘못 알고 있는 사용자들도 여럿 봤음.  그냥 그럭저럭 사용하기 편하게 만든 범용코드 정도라고 생각하는데...)
* 관련 컨퍼런스 같은데 가보면 해석 소프트웨어 영업사원들이 기술자보다 더 많음.  현업 기술자들은 한가롭게 컨퍼런스 같은데 다닐 시간이 없으니...  이런 상황이 참 딱함.
* 현업 기계공학 설계자들이 너무 보수적이고 귀챠니즘이 심한 경향.  오픈소스 좀 해 보다가 어렵고 귀챦고 복잡하니까 에이 못쓰겠네 하고 던져버리고, "역시 Ansys지"라고 말하는 식의 장면이 많음.  물론 당면 업무 자체만 "빨리빨리" 끝내서 모면해야 상사한테 안 깨지니까 당연한 것이긴 한데, 그래도 기술자라면 기술세계에서 뭔가 기여해야 한다는 퍼블릭한 이상주의 같은 것을 어느정도 마음속에 가지고 있어야 하지 않을까 싶음.  돈 버는 것만 목적이라면 왜 기술자를 하는지 모르겠음.  그냥 부동산 공인중계사 자격증 따서 아파트 매매하면 그 좋은 머리로 돈을 더 잘 벌 수 있었을텐데.
* 이래가지고 미래의 기술경쟁에서 계속 살아남을 수 있을까 좀 걱정됨.  내가 너무 비판적인가...

