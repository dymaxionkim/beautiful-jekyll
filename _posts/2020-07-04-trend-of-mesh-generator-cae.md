---
layout: post
published: true
title: 'Trend of Mesh Generator, CAE'
subtitle: Trend of Mesh Generator
date: '2020-07-04'
bigimg: /img/bigimg51.jpg
tags: software
image: 'https://ngsolve.org/images/blog/torusmesh.png'
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

* [https://ngsolve.org/](https://ngsolve.org/)
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

### 6. Midas MeshFree

* [https://kor.midasuser.com/meshfree/](https://kor.midasuser.com/meshfree/)
* 국내 CAE 소프트웨어 업체가 만든 제품명이자 마케팅 용어
* 마케팅으로 "격자를 짤 필요가 없다"고 표현하고 있는데 이 표현은 사실 문제가 있다고 생각됨
* 메쉬를 실제로 생성을 할 필요가 없다는 것이 아니고, 메쉬 생성의 어려움을 줄여준다는 의미
* 이 방식은 가상의 Voxel 형태의 Grid Volume을 만들고, 이것을 3D Geometry와 겹친 후, 교집합 부분만 남기는 식으로 잘라주는 방식임 (경계 무격자법)
* 이후 경계면 처리는 별도의 공식으로 오류가 적게 나도록 살짝 손봐줌
* 나머지 Solver 부분은 기존의 MidasNFX 제품과 별 차이 없음
* UI 디자인도 예쁘기는 하지만 사실 별 특징이 없고 기능이 상당히 단순하게 정리되어 있음

### 7. Cubit

* 미국 국립 Sandia 연구소에서 개발 [https://cubit.sandia.gov/](https://cubit.sandia.gov/)
* Midas MeshFree의 아이디어의 원조격이 되는 메쉬생성기 (경계 무격자법)
* 구현된 수준은 Midas MeshFree보다 훨씬 더 우수함 (단순 육면체 격자 뿐만 아니라 더 복잡한 형태까지 대응)
* 미국의 단체(연구소)에서는 무료로 사용 가능.  해외에서는 무료버전 사용 불가능.
* 상업화된 버전은 coreform사에서 제, 현재는 한단계 더 나아간 신기술을 적용한 제품 출시 준비

### 8. Coreform Crunch

* [https://coreform.com/](https://coreform.com/)
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
