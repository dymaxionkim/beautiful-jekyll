---
layout: post
published: true
title: Blender for Product Visualization
image: >-
  https://user-images.githubusercontent.com/12775748/35767436-946bed22-092f-11e8-93ff-53a1c2c47c69.png
tags: software
bigimg: /img/bigimg42.jpg
date: '2018-02-03'
subtitle: Realistic Render for Product
---

## Blender for Product Visualization
* [Slide](https://www.slideshare.net/dymaxionkim/20140514-team-blenderv01)
* [Blender를 제품설계자용 렌더링 툴로 활용하기](https://dymaxionkim.blogspot.kr/2014/04/blender.html)
* 본 글의 목표는, 블랜더의 모든 기능을 다 활용하자는 것이 아니라, 오로지 내장된 Cycles 랜더러를 이용해서 이미 설계완료된 제품설계 데이타를 불러들여서 고품질의 랜더링을 하는 간단하고 신속한 방법을 고찰한 것이다.
* 따라서 블랜더 자체적인 형상모델링 기능 등은 여기서는 쓸모가 없다.  3D CAD 소프트웨어에서 수행된 설계 모델링 데이타를 블랜더로 불러들이는 워크플로우에 관심을 두기로 한다.
* 또한 Cycles 랜더러 관련된 부분 역시, 모든 기능을 다 익힌다기 보다는 최대한 원래의 기본 설정을 그대로 두고, 꼭 필요한 부분만 건드려서 최단시간내에 최소한의 공수로 그럭저럭 볼만한 랜더링을 얻어내 주는데 목적이 있다.
* 실무에서 시간을 아끼는 것은 굉장히 중요하다.  가장 신속하게 랜더링 결과를 보여주는 상용 Keyshot 소프트웨어까지는 아니더라도 그에 육박하는 신속성을 보여줄 수 있다는 점은 확인했다.
* 이런 종류의 포토리얼리스틱 랜더링이 필요한 경우는, 보통 제품개발 과정에서 워킹목업을 제작한다고 할 경우, 설계데이타 불출후 디자인리뷰 및 워킹목업 부품의 가공기간 등을 고려할 경우 통상 2~4주 가량의 시간적인 공백이 발생하게 된다.  이 기간 동안에 실물이 제작되기까지 손가락 빨고 기다리느니 뭐라도 하는게 좋지 않느냐 이런 상황이 올 수 있다.  그때 랜더링을 해서 협업자들에게 배포하는 것이다.  이를 통해 최종 결과물에 대한 확신을 더 가질 수 있거나, 미처 고려하지 못한 수정사항을 도출해 낼 기회를 더 가질 수 있을 것이다.  제품의 도색 컬러 결정에도 도움이 될 것이다.


## 설치
* 우분투에서는 다음과 같이 편하게 설치하려면...  [참고](https://askubuntu.com/questions/169542/how-do-i-install-the-latest-blender-3d-builds-from-a-ppa#169546)

```bash
sudo add-apt-repository ppa:irie/blender
sudo apt update
sudo apt install blender
```

* 하지만 위와 같은 APT 관리자를 이용한 설치 방법은 일반적으로 권장되지 않는 편이다.  블렌더 공식 홈페이지에 가서 직접 다운로드 받아서, 압축을 풀고 그 안의 실행파일을 직접 실행하는 것이 더 일반적인 것 같다.

* 최신버전을 직접 다운로드 받아서 압축을 풀어서 사용하려면... [다운로드](https://www.blender.org/download/)

* 이유는, 블렌더의 경우 세부적인 기능 차이 및 애드온 지원 등의 문제가 있을 수 있어서 항상 최신버전을 자동으로 유지하는 것이 반드시 유리하지만은 않기 때문에, 필요할 때 자신의 의지로 버전업을 실시하는 것이 더 좋기 때문이다.


## 자습 참고
* [Learning Flow: Introduction to Blender](https://cgcookie.com/flow/introduction-to-blender) : 입문 동영상 강의
* [네이버 까페](https://cafe.naver.com/blender3d)
* [Blender Cycles memo](http://cycles.wiki.fc2.com/) : 일본어니깐 번역해서 보면 된다.
* [Blender Manual](https://docs.blender.org/manual/en/dev/index.html)
* [Blender Guru](https://www.blenderguru.com)
* [Blender Nation](https://www.blendernation.com)
* [Working with STP and STL files in Blender](https://www.linkedin.com/pulse/working-stp-stl-files-blender-thomas-aurich)
* [Using CAD STEP/STL files in Blender](https://www.linkedin.com/pulse/using-cad-stepstl-files-blender-thomas-aurich)
* [Chocofur blog](http://www.chocofur.com/)
* [What Makes a Good HDRI](http://adaptivesamples.com/2016/02/23/what-makes-good-hdri/)


## Materials (재질)
* [Blendermada](http://blendermada.com) : Free Materials Add-on
* [BlendSwap](https://www.blendswap.com): 회원가입 
* [Cycles Material Vault](https://www.cyclesmaterialvault.com) : 유료


## HDRI (배경그림)
* [Free HDRI Sky](http://www.hyperfocaldesign.com/free-hdri-sky/)


## Product Visualization
* 그럼 Blender에 관한 기본적인 배경지식을 갖추었다고 가정하고, 제품 설계데이타를 블랜더로 불려들이고 그것을 랜더링하는 과정을 따라가 보자.


### 3D CAD 파일 준비
* 설계자가 사용하는 CAD 소프트웨어는 여러가지로 다양할 것이다.  그러나 대체로 문제될 것은 없다.  심지어 오픈소스 FreeCAD에서도 별 문제가 없었다.
* 다만 본 예제에서는 PTC CREO에서 출발하도록 해 보자.
* 모델링 데이타의 색상은 가급적 실제 현물 색상이 가깝도록 맞춰주는 것이 향후 작업량을 줄여줄 수 있다.

![001](https://user-images.githubusercontent.com/12775748/35767374-a256dc04-092e-11e8-8fdd-5e9a605318e8.png)


### 데이타 전달용 파일 포멧의 선정
* PTC CREO와 같은 고급 소프트웨어에서는 다른 포멧으로 데이타를 저장하는 기능도 잘 발달되어 있다.  저가형 또는 오픈소스 소프트웨어에 비해 같은 포멧을 만들더라도 더 많은 옵션을 줄 수 있게 제공이 되는 것 같다.
* 블랜더는 직접 STEP과 같은 솔리드데이타를 읽어들이지는 못하기 때문에, 매쉬화된 데이타를 만들어 주어야 한다.  이를 위해 가장 일반적으로 사용하는 STL 파일도 좋지만, 이 포멧은 여러개의 부품으로 구성된 데이타구조를 다루는데는 적합하지 않다.  웹표준으로 쓰는 WRL 같은 포멧도 좋을 것 같지만, 실제 테스트해 본 결과 역시 별로 좋지 않았다.  부품의 결합구조 및 컬러 등 재질정보는 그대로 잘 보존되어 넘어오지만, 불행히도 온갖 쓸데없는 잡정보들(점,선등)도 많이 섞여 들어오기 때문에 데이타가 너무 지저분했다.  CREO에서 내보내주는 SLP 포멧도 좋겠지만, 불행히도 블랜더에서 공식적으로 제공하는 읽어들이기 기능은 없다(2.4버전용의 임포터 애드온은 있지만 지금 시점에서는 쓸모가 없다고 봐야겠다).
* 여러가지 테스트해 본 결과, 가장 매끄럽게 데이타 교환이 가능한 포멧은 바로 Wavefront OBJ 포멧이었다.  CREO에서 이 포멧을 출력하면, MTL 확장자의 보조파일도 함께 생성되는데, 여기에 색상 등의 재질 정보가 들어있고 블랜더가 OBJ 파일을 읽어들일 때 이 파일이 함께 있으면 자동적으로 반영이 되는 것을 확인했다.  또한 OBJ 포멧은 부품별로 구분해서 오브젝트로 불러들여주기 때문에 블랜더 내부에서의 후반작업 역시 편해진다.

|포멧         |멀티바디 대응  |재질 색상 정보|데이타 간결성|블랜더 임포트|
|-------------|---------------|--------------|-------------|-------------|
|STL          |X              |X             |Good         |O            |
|WRL          |O              |O             |Bad          |O            |
|SLP          |O              |O             |Good         |X            |
|Wavefront OBJ|O              |O             |Good         |O            |

* 다만, 부품 중에서 형상이 상당히 복잡하거나 좌표정밀도 문제등이 있을 경우에는, 해당 부품이 면들(Facets)별로 다 깨져서 블랜더로 불러들여지는 경우가 가끔 있다.  이때는 해당 부품만 별도의 OBJ 파일로 만들어서 따로 불러들여서 모든 요소들을 합치는 식(join)으로 처리하면 된다.


### WaveFront obj 파일 준비
* PTC CREO에서 제품의 어셈블리 파일을 띄운다.
* `File - Save As` 해서 팝업창에서 출력파일 종류를 `Wavefront(*.obj)`로 골라준다.
* `File Name`은 적절히 변경해 준다.  저장할 장소도 찾아가 준다.

![002](https://user-images.githubusercontent.com/12775748/35767375-a27ffc60-092e-11e8-893e-0a852ace0ee2.png)

* `OK`해 주면, `Export Wavefront` 팝업창이 뜬다.
* 여기서 `Groups to Export` 카테고리에서 `All`을 눌러주고, 곧바로 기준으로 삼을 좌표계를 선택한다.  그러면 현재 열려진 어셈블리 전체가 목록에 등재된다.
* `Chord Height`란에는 `0`을 써준다.  그러면 현재 형상에서 가장 조밀하게 생성된다.  다른 옵션도 건드려 줄 수는 있지만 여기서는 일단 이정도만 건드려 주자.
* `OK`를 누르면 파일 생성이 시작된다.  파일의 크기에 따라 시간이 좀 걸릴 수도 있다.  완료되면 `*.obj`, `*.mtl` 파일이 생성된다.
* 보통 이와 같이 `All`로 한 방에 제대로 변환이 되는데, 간혹 깨지는 부품이 있다.  이때는, `All` 대신 깨지는 부품만 빼고 다른 부품들을 선택해서 출력해 주고, 깨지는 부품은 별도로 따로 출력해서 나중에 블랜더에서 각각 임포트해주고 블랜더 내에서 깨진 것들을 합쳐주면 된다.

![003](https://user-images.githubusercontent.com/12775748/35767376-a2a61288-092e-11e8-9edc-e132c74baea5.png)

* 이상 PTC CREO에서 작업은 끝났으므로 종료시키면 된다.


### Import into Blender
* 일단 블랜더를 실행시키면 기본 환경이 나온다.  본 예제에서는 아래 그림에서, 거의 빨간색으로 둘러친 부분만 사용한다고 보면 된다.

![004](https://user-images.githubusercontent.com/12775748/35767377-a2cc40b6-092e-11e8-90c5-af3e8028421c.png)

* 기본적으로 육면체 하나가 들어 있는데, 이건 쓸데 없으므로 `Del` 키를 눌러주고 확인해서 삭제한다.

![](https://user-images.githubusercontent.com/12775748/35773845-b1a6960e-09a1-11e8-99ce-4cf74ed92b32.png)


* 그 다음, `File - Import - Wavefront(.obj)` 한 후 필요한 OBJ 파일을 읽어들인다.  미리 준비한 여러개의 OBJ 파일을 그대로 불러들여 겹쳐도 된다. (물론, CREO에서 기준 좌표계를 항상 동일한 것으로 해서 출력해 두었다면 위치도 제대로 잡아질 것이다.)
* 개중에 깨지기 때문에 별도의 OBJ 파일로 만든 파트가 있다면, 우측 상단부의 `Outliner` 트리에서 다른 것들을 전부 Hide 시키고, 합칠 것들만 남겨둔 후, 단축키 `B` 또는 `Select - Border Select`로 합치기를 원하는 것들을 전부 긁어서 선택한다.  그 다음 단축키 `Ctrl-J` 또는 `Object -Join` 해 주면 선택된 것들을 모두 하나로 합칠 수 있다.

![](https://user-images.githubusercontent.com/12775748/35773846-b1e2866e-09a1-11e8-97e7-d6fee7339675.png)

![](https://user-images.githubusercontent.com/12775748/35773847-b2116fa6-09a1-11e8-8ecb-2c7bb80074d8.png)

* 가급적 `Outliner` 트리에서 각각의 부품들(오브젝트들)의 명칭을 구분하기 쉽게 바꿔주는 것이 깔끔할 것이다.

![](https://user-images.githubusercontent.com/12775748/35773848-b2410220-09a1-11e8-8225-b40b3deaefef.png)

![005](https://user-images.githubusercontent.com/12775748/35767378-a2f2c916-092e-11e8-892c-c96c7ee8a213.png)


### Mesh 정돈
* 개중에 매쉬가 너무 성글어서, 랜더링 후에 각져서 보이는 경우에는 해당 매쉬를 뭉개주는 것이 좋겠다.
* 해당 오브젝트를 선택해 준 다음(해당 오브젝트 위에서 마우스 오른쪽 버튼 누르면 선택됨), 현재의 `Object Mode`를 `Edit Mode`로 바꾼다.

![](https://user-images.githubusercontent.com/12775748/35773857-b3e9cd32-09a1-11e8-9143-8ebe5f69da30.png)

* 그 다음 `Mesh - Faces - Shade Smooth`를 해 주면 매끄러운 면으로 뭉개져서 랜더링이 된다.
* 다만 충분히 조밀하게 만든 것이라면 생략해도 굳이 눈에 띄게 각져보이지는 않으므로 필요할 때 필요한 오브젝트만 손 봐주면 될 것 같다.

![006](https://user-images.githubusercontent.com/12775748/35767379-a3195fea-092e-11e8-99e6-7abc53ac488e.png)

![007](https://user-images.githubusercontent.com/12775748/35767380-a341b3a0-092e-11e8-9f03-119f3e446c19.png)


### Resize
* 단축키 `키패드 0` 또는 `View - Camera` 해 주면, 기본적으로 이미 만들어져 있는 카메라의 시야로 전환된다.
* 임포트한 오브젝트들이 너무 커서 리사이즈 할 필요가 있으므로, 마우스휠로 전부 다 보이게 한 다음, 카메라/조명을 Hide 시켜주고 나서, 단축키 `B` 또는 `Select - Border Select`로 리사이즈할 것들을 전부 긁어서 선택한다.
* 이후 좌측 상단부 `Tools` 탭 안에서 `Scale`을 눌러준 후 마우스를 그대로 좌우로 움직여서 원하는 사이즈로 조절한다.
* 아울러 `Tanslate` 및 `Rotate`를 이용하여 원하는 방향과 위치에 놓이도록 조절해 준다.

![](https://user-images.githubusercontent.com/12775748/35773849-b26fc68c-09a1-11e8-84b4-e0c980131458.png)


### Materials
* 각각의 부품의 재질을 알맞게 설정해 주는 것이 좋겠다.
* 어렵게 스스로 재질을 만드는 것은 공부가 좀 필요하고 너무 노가다이기 때문에, 적당한 머터리얼 라이브러리를 애드온으로 하나 골라서 설치하는 것이 편하겠다.
* 여기서는 [Blendermada](http://blendermada.com/addon/) 에서 애드온 코드를 하나 다운로드 받아서 설치하자.  다운로드 받으면 .py 파일이 하나이다.
* 블랜더에서 `File - User Preferences - Add-ons - Community`로 찾아들어간 다음, `Material: Blendermada Client`를 체크해 주고, `▷` 모양을 눌러서 안을 들여다 보면 `Use a big preview`도 체크해 준다.
* 그리고 창의 좌측하단에 `Save User Settings` 눌러주고 창을 닫으면 된다.

![](https://user-images.githubusercontent.com/12775748/35773850-b2a09a5a-09a1-11e8-9867-ed514b0fb4e5.png)

![](https://user-images.githubusercontent.com/12775748/35773852-b2cd2566-09a1-11e8-8164-c5cd221ae5b2.png)

* 이제 재질을 줄 오브젝트를 선택한 후, 머터리얼 설정에 들어가서 보면 `Blendermada Client` 카테고리가 생겨있을 것이다.  여기 머터리얼들은 대부분 Cycles 랜더러를 위한 것이므로, 상단부 중앙에서 엔진을 Cycles로 바꿔준다.
* 그리고 `Update`를 눌러주면 카테고리와 머터리얼들이 들어와서 보인다.
* 이중에 필요한 걸 골라주고, `Preview`를 누르면 대충 어떤건지 알 수 있고, 다시 `Preview` 눌러서 그림을 닫아준다.
* 이제 `Import`를 누르면 골라진 재질이 들어와서 현재 선택되어 있는 오브젝트에 적용이 된다.  가급적 들어온 머터리얼의 명칭은 편한 것으로 잘 정리해서 바꿔준다.  필요할 경우 페인트 같은 것의 컬러를 바꾸는 등의 설정을 해서 손봐줄 수 있다.

![](https://user-images.githubusercontent.com/12775748/35773853-b2fda7f4-09a1-11e8-8a8f-75b9f3a3d3cd.png)

* 이런 과정을 반복해서 재질을 각각의 오브젝트에 전부 다 매겨준다.
* 본인의 경우엔, 모든 오브젝트들을 일일이 다 바꿔주기가 너무 번거롭기 때문에 외관으로 드러나는 주요 부품들만 재질 적용해 준다.  나머지 잘 안 보이거나 덜 중요한 것들은 이미 색상 정도는 잘 들어와 있기 때문에 굳이 세밀하게 재질을 매겨주지 않아도 별 차이 없는 것 같다.


### World
* 이제 지구본 모양 아이콘을 눌러 환경(World)을 설정해 본다.
* 그냥 단색 컬러로 하는 것 보다는 주변 환경 그림을 입혀주는 것이 더 현실감이 있기 때문에 그렇게 해 보자.
* 구글에서 `hdri`로 검색해 보면 많은 환경 그림들을 찾아볼 수 있다.  적당한 걸 하나 골라서 다운로드 받아서 현재 작업중인 폴더에 함께 넣어놓는다.
* World 설정의 `Surface`안에서 `Color:` 카테고리에 `Environment Texture`를 선택한다.  그리고 `Open`을 눌러서 환경 그림 파일을 고른다.
* `Strength`로 밝기를 바꿔준다.  일단은 기본값으로 그냥 둬 보고, 너무 어둡다 싶으면 나중에 높여보던가 하면서 조절한다.

![](https://user-images.githubusercontent.com/12775748/35773854-b34bd94c-09a1-11e8-9cab-19bd44be28ca.png)


### Render
* 랜더링 속도를 높이기 위해 GPGPU 기능을 살리는 것이 더 좋겠다.
* 가장 좋은 하드웨어는 당연히 NVIDIA QUADRO 그래픽카드일 것이다.
* `File - User Preferences - System`으로 찾아들어가면, `Cycles Compute Device:` 카테고리가 있는데 현재 자신의 하드웨어 환경을 인식해서 표시해 주고 있을 것이다.  여기서 CUDA 선택하고 그래픽카드 체크해 준다.
* 그리고 카메라 아이콘 눌러서 랜더링 설정하는 부분에서 `Render` 카테고리에서 `Device:`를 `GPU Compute`로 해 준다.
* 그리고 이제 `Render` 버튼을 때려주면 랜더링이 된다.

![](https://user-images.githubusercontent.com/12775748/35773855-b3787588-09a1-11e8-8328-6b1b4bd02b2e.png)

* 랜더링이 다 되었으면, 단축키 `F3` 또는 `Image - Save as Image` 눌러서 그림으로 저장해 준다.

![011](https://user-images.githubusercontent.com/12775748/35767384-a3f87f54-092e-11e8-8c0f-cf21e44e4687.png)

* 그리고 다시 3D View 모드로 돌아오면 된다.

![](https://user-images.githubusercontent.com/12775748/35773858-b41419c0-09a1-11e8-9e2f-6c679cb52d70.png)

* 3D View 모드에서, 쉐이딩 상태를 변경하려면 아래와 같이 고르면 된다.

![](https://user-images.githubusercontent.com/12775748/35773856-b3a4a428-09a1-11e8-84bd-9badb6f59959.png)


### 기타
* 기타 카메라, 조명, 랜더링 설정 등을 이리저리 만져보면서 가지고 놀면 될 것이다.  자세한 설명은 생략한다.


## 결론
* 이상 가장 간단하게 기본적인 제품 랜더링 순서를 써 보았다.
* 구조설계 엔지니어가 제품 랜더링을 할 경우는 대체로 잘 없는데, 간혹 필요한 경우가 꼭 있다.  그때 자신이 사용하는 3D CAD 소프트웨어에 내장된 랜더러가 너무 퀄리티가 안좋거나 또는 옵션이 구매되지 않았을 경우, 또 그나마 편하게 쓸 수 있는 상용 랜더러인 Keyshot을 구매할 수 없는 경우...  이럴 때 오픈소스 랜더러 대안이 있다면 좋을 것이다.  여기에 부응하는 것이 바로 Blender Cycles 랜더러라고 생각된다.
* 실제로 이정도 기본적인 셋팅으로 랜더링 해 보니, 실제 작업시간은 Keyshot을 사용하는 경우보다 딱히 더 오래걸리지도 않는 것 같다.  그리고 꽤 유용하다.
