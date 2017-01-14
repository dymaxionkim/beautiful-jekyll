---
layout: post
published: true
title: MotionControl
subtitle: in Univ., 1999
date: '1999-12-31'
---

## Summary
*


## 4-DOF Manual Rig

### 설계 : 개략적인 형상의 결정과 그 이유

#### 제한 조건

본 기계는 총 4자유도를 가지고 있으며, 이는 Pan, Tilt, Lift, Track 동작으로 구분된다.
각 동작의 기구적인 Limit 목표를 결정하기 위하여 다음과 같은 기준이 구체적으로 제시되었다.

  1. Pan : 정면상태에서 좌우 180도 이상 확보.
  2. Tilt : 수평상태에서 상하 90도 이상 확보.
  3. Lift : Camera 위치의 최저점은 0.7m 가량, 최고점은 2m 가량 확보.
  4. Track : 전후진 범위 3m 이상 확보하되, 약 1m 높이의 피사체 테이블 위로 2m 가량 밀고 들어갈 수 있도록 할 것.

이밖에 Roll, Rotate 동작은 생략되었다.  따라서 일정공간상에서 Camera는 모든 위치와 방향으로 이동될 수는 없다.

이러한 제한된 동작은, 약 1m 높이의 테이블 위에 피사체가 존재하는 스튜디오 내의 환경에 적합하도록 고려되었다.
따라서 본 기계는 클레이 에니메이션 촬영만을 위한 전용 장치이다.
특히 이송운동을 위한 동력은, 핸들을 돌려주는 수동식으로 함으로써 불필요한 복잡성을 제거할 수 있었다.
걱정되는 점은, 핸들의 위치가 오퍼레이터가 접근하기 힘든 곳에 있을 수 있어 사용에 불편함과 위험성을 가지게 된다.


#### 최초의 디자인

선행 검토를 위해 여러가지 관절 레이아웃들을 고려하였다.

![_1-dymaxion](https://cloud.githubusercontent.com/assets/12775748/21952757/3e4681f2-da67-11e6-81c6-c788f6635033.gif)
![_2-dymaxion](https://cloud.githubusercontent.com/assets/12775748/21952755/3e46665e-da67-11e6-9bf1-30c4a5b58bff.gif)
![2-dymaxion](https://cloud.githubusercontent.com/assets/12775748/21952753/3e461dde-da67-11e6-9fbe-1a9e2a3e3e9b.gif)
![-dymaxion](https://cloud.githubusercontent.com/assets/12775748/21952756/3e466230-da67-11e6-992e-9d50fd62c0f8.gif)
![2-dymaxion](https://cloud.githubusercontent.com/assets/12775748/21952758/3e46ac36-da67-11e6-8e7b-e731d3de768a.gif)
![-dymaxion](https://cloud.githubusercontent.com/assets/12775748/21952754/3e464908-da67-11e6-81ee-6fbadf7c068f.gif)
![2-dymaxion](https://cloud.githubusercontent.com/assets/12775748/21952760/3e7798f0-da67-11e6-9717-74892d386881.gif)
![3-dymaxion](https://cloud.githubusercontent.com/assets/12775748/21952759/3e771196-da67-11e6-97eb-d80afa66f717.gif)
![-dymaxion](https://cloud.githubusercontent.com/assets/12775748/21952761/3e780e2a-da67-11e6-8ef7-2cc4822e92df.gif)


최초의 디자인은 4자유도를 주면서 직교운동을 하는 형태를 생각하여 보았다.  이러한 형태를 사용하면, 기계가 차지하는 공간이 커지고 안정도에 문제가 있을 것으로 보아 약간 다른 형태로 발전시켜 보았다.

![idea_sketch_first-dymaxion](https://cloud.githubusercontent.com/assets/12775748/21952688/bb13cf56-da66-11e6-8721-b1ad40882c4e.jpg)
_직교 운동을 하는 모델의 아이디어 스케치_


따라서 Boom을 리프트 시키는 동작을 통하여 들어올리도록 하는 구조가 제안되었고 검토되었다.

![idea_sketch_second-dymaxion](https://cloud.githubusercontent.com/assets/12775748/21952691/bb1a54f2-da66-11e6-91dd-1a879630b816.jpg)
_리드스크류를 이용한 형태의 아이디어 스케치_


헤드부분의 운동은, 단순한 Pan, Tilt 가 필요하였는데 이를 위해 아래 그림과 같은 세 가지의 형태를 검토하였으며, 최종적으로 마지막의 것을 선택하였다.

![idea_sketch_about_head-dymaxion](https://cloud.githubusercontent.com/assets/12775748/21952689/bb144346-da66-11e6-9abd-a6426923cd05.jpg)
_헤드부분을 위한 아이디어 스케치_


각 운동부분의 각도측정을 위해 증분형 엔코더를 사용하기로 하였는데, 부착위치는 최종 회전축에 직결하여 전동계통의 오차를 극복하도록 하였다.  엔코더의 신호는 카운터 모듈을 부착하여 읽을 수 있도록 하였다.

![idea_sketch_about_encoder-dymaxion](https://cloud.githubusercontent.com/assets/12775748/21952687/bb11cff8-da66-11e6-84be-971dfff3ad72.jpg)
_각도측정을 위한 장치의 스케치_



#### 대략 설계

대략적인 형태를 상상해 보기 위하여, 대략적인 치수를 넣어 도면을 작성하여 보았다.

![rough_design-dymaxion](https://cloud.githubusercontent.com/assets/12775748/21952693/bb335e98-da66-11e6-89d9-1b8e60170dd5.gif)
_대략설계의 조감도_

여기서 나타난 문제점과 불확실함을 조사를 통하여 확보된 자료를 근거로 상세하게 설계도를 작성할 수가 있었다.


#### 상세 설계

상세설계도면은 아래에 AutoCAD Release14 file로 저장하였다.

![real_design-dymaxion](https://cloud.githubusercontent.com/assets/12775748/21952692/bb328bda-da66-11e6-8b49-dd1f27b11956.gif)
_상세설계의 조감도_


#### 랜더링 그림들

![01-dymaxion](https://cloud.githubusercontent.com/assets/12775748/21952678/bab3423a-da66-11e6-9c44-6db5d3400572.gif)
![02-dymaxion](https://cloud.githubusercontent.com/assets/12775748/21952682/baf03848-da66-11e6-9860-2820c071c73b.gif)
![03-dymaxion](https://cloud.githubusercontent.com/assets/12775748/21952680/baefc93a-da66-11e6-9177-292e52656c9d.gif)
![04-dymaxion](https://cloud.githubusercontent.com/assets/12775748/21952681/baefceee-da66-11e6-968a-f07256b29c66.gif)
![05-dymaxion](https://cloud.githubusercontent.com/assets/12775748/21952683/baf12514-da66-11e6-9c32-70c426f4eed2.gif)


### 제작 목표와 방향의 규정, 그리고 제작 계획 수립

#### 제작 목표와 방향

* 개괄

본 기계는 Stop Motion 촬영을 위한 Camera의 이송장치로서 제작된다.

장착되는 카메라는 베타캠, 16mm 아리플렉스, 35mm 미첼 카메라 등이며 그 페이로드는 10kg에서 최고 30kg 까지 될 것으로 예상된다.

![fries_mitchell_35r_camera-dymaxion](https://cloud.githubusercontent.com/assets/12775748/21952686/bb1174d6-da66-11e6-890e-509b0689f412.gif)
_Fries Mitchell 35R Camera_

정지촬영을 위한 특성을 만족하기 위해서는 확실하게 카메라를 고정시킬 수 있는 강건성과 넓은 범위에 걸쳐 움직일 수 있는 자유도가 확보되어야 하는데, 이 두가지 상반된 요소의 절충점을 찾아내는데 주안점을 둔다.

또한 사용중 예상되는 상황에 대처가능하도록 간단한 사용법과 내구성이 요구된다.

* 재료 및 구조관련

1. 재료는 두께 3mm 의 스텐레스 강판사용과 판금가공을 기본으로 한다.
2. 하중 버팀을 위한 최소한의 재료만을 사용하여 낭비를 줄인다.
3. 직선위주의 단순한 형태를 이루어 제작을 용이하게 한다.
4. 하중을 받는 축이음 부분에는 내경 30mm 의 UKF 207 베어링(베어링 하우징과 축물림 너트 장착)과 스러스트 베어링(샌드위치식의 베어링)을 사용하여 강인성을 보장한다.


* 전동장치 관련

1. 모듈화된 기어박스를 사용하여 신뢰성을 높인다.
2. 기어박스 종축은 굵게 하여 충분히 튼튼하게 한다.
3. 수동 핸들 부착 위치에 차후 서보모터를 부착할 수 있도록 고려한다.
4. Boom 의 하중을 지탱하기 위해 리드스크류(Lead Screw Device)를 사용한다.


* 관절의 이동 한계 관련

1. 헤드의 Tilt, Pan 운동은 부품간 간섭이 없도록 하여 360도 회전이 가능하도록 한다.
2. Lift 운동은 최소 -5도에서 +45도 까지 움직일 수 있도록 한다.
3. Track 운동은 2m 길이의 레일을 연결하여 연장할 수 있도록 한다.
4. 레일은 2조를 완성하여 연장길이 4m 가 되도록 하며, 이때 왕복운동 행정길이는 약 3m 가 된다.
5. 피사체가 놓인 Set table 위로 카메라가 1.5m 이상 뻗을 수 있도록 한다.

![idea_sketch_about_motion-dymaxion](https://cloud.githubusercontent.com/assets/12775748/21952690/bb14f8ea-da66-11e6-80f4-9e2cd0ae21d5.jpg)
_Set table 위로 카메라가 비행할 수 있도록 한다_


* 오차 및 공차 관련

1. 하중에 의한 재료의 탄성 변형이 있을 수 있으나 경험적으로 이는 무시할 만 하다고 본다.
2. 재료의 변형보다 심각한 문제는, 축이음시 체결력이 약하여 끄덕거리는 현상이 있을때라고 본다.  이 부분은, 넓은 면적의 스러스트 베어링과 축이음 후 양 축을 꽉 눌러주는 볼팅 작업을 더해 줌으로써 해결하려 한다.
3. 기어박스에서 발생하는 Back-lash(기어가 약간 헛도는 현상)에 대해 대항할 수 있도록 하기위해 변위측정용 엔코더를 맨 마지막 종축에 부착하려 한다.
4. 엔코더의 분해능은 국산(LG산전 또는 Autonics사)의 경우 최고 2000 Pulse/Revolution 이 있으며, 이를 사용할 경우 분해능은 0.18도가 된다.  2000 펄스 제품이 재고가 없을 경우 1000펄스 제품을 사용하면 된다고 본다(분해능 0.36도).

![encoder-dymaxion](https://cloud.githubusercontent.com/assets/12775748/21952684/baf19396-da66-11e6-8254-342f46e12e70.jpg)
_Resolution 2000 Pulse Encoder Device_


#### 예상 비용 산출

아래에 예상되는 견적을 제시하여 보았다.  예상되는 비용은 재료비 밑 가공비를 합하여 600여만원이 소요되는 것으로 나타났다.


#### 제작계획

제작을 위한 비용은, 구체적인 설계가 완료된 후 시장조사를 통하여 견적을 산출한 것을 근거로 한다.
제작장소는 학교내 공용공작실을 이용하도록 한다.





### 결론 : 예산 집행 내역과 맺음말

#### 예산집행 내역

**총계 : 5,409,870 원**

기타 식사비나 차비 등은 영수증을 확보하지 못하여 계산되어있지 않다.  예상되었던 견적과 크게 차이가 나지 않음을 알 수 있다.



#### 평가

제작된 기계를 테스트해 본 결과, 좌우방향 및 상하방향의 진동이 존재함을 알 수 있었다.  진동상태에서는 피사체를 촬영하기에 곤란할 정도이나, 진동이 충분히 감쇠하고 난후 촬영시에는 큰 이상이 발견되지 않았다.  진동의 원인은 다음과 같이 생각된다.

  - Boom을 지지하는 타워의 비틀림이 좌우방향의 진동을 유발
  - Track이 전체 무게를 견디지 못하여 탄성변형을 일으키며 이는 상하진동을 유발

따라서 이러한 진동을 줄이기 위해서는 다음과 같은 보완이 이루어진다면 효과를 볼 수 있다고 본다.

* 타워의 ㄷ 자 단면을 부재를 부착하여 ㅁ 자 단면으로 고친다면 비틀림을 효과적으로 줄일 수 있으므로 좌우진동이 크게 감소할 것으로 기대됨

![error01-dymaxion](https://cloud.githubusercontent.com/assets/12775748/21952679/bad4bc6c-da66-11e6-83cc-fa263c74cd65.jpg)

* Track 의 떠있는 부분에 각목 등으로 지지한다면 상하진동을 막을 수 있음

![error02-dymaxion](https://cloud.githubusercontent.com/assets/12775748/21952685/baf6520a-da66-11e6-8ca7-090cfa7d6d0b.jpg)


이밖에 다음과 같은 문제점이 발견되었다.

  - Track  운동을 위한 기어장치에 내장된 타이밍 벨트의 장력이 부족하여 탈조현상이 발생
  - 기어박스 조립시 부정확성으로 인한 토크의 불규칙성 발생
  - 분해조립에 어려움이 많음

이러한 문제점들은 사용과 함께 개선되어 나갈 수 있으리라 생각된다.

#### 제작 사진들

![05-dymaxion](https://cloud.githubusercontent.com/assets/12775748/21952711/1eaff724-da67-11e6-8101-f0073ac802ca.jpg)
![12-dymaxion](https://cloud.githubusercontent.com/assets/12775748/21952713/1eecbb0a-da67-11e6-9852-6c5069483e9a.jpg)
![13-dymaxion](https://cloud.githubusercontent.com/assets/12775748/21952712/1ed0fd5c-da67-11e6-8ae5-788fd03f6bca.jpg)
![14-dymaxion](https://cloud.githubusercontent.com/assets/12775748/21952715/1ef02b50-da67-11e6-9b54-13c21151e9cf.jpg)
![15-dymaxion](https://cloud.githubusercontent.com/assets/12775748/21952714/1eefc124-da67-11e6-93ed-b652fe5791c8.jpg)
![16-dymaxion](https://cloud.githubusercontent.com/assets/12775748/21952716/1ef1f976-da67-11e6-9481-97333b63808a.jpg)
![17-dymaxion](https://cloud.githubusercontent.com/assets/12775748/21952718/1ef65746-da67-11e6-98a8-ffde9f4f996b.jpg)
![18-dymaxion](https://cloud.githubusercontent.com/assets/12775748/21952717/1ef4c606-da67-11e6-8a9f-4247f295597a.jpg)
![19-dymaxion](https://cloud.githubusercontent.com/assets/12775748/21952719/1f0dad24-da67-11e6-8739-7279a91a89d9.jpg)
![20-dymaxion](https://cloud.githubusercontent.com/assets/12775748/21952720/1f10c50e-da67-11e6-9c2e-8013519b15af.jpg)
![21-dymaxion](https://cloud.githubusercontent.com/assets/12775748/21952721/1f12140e-da67-11e6-849a-f7847a2aed16.jpg)
![22-dymaxion](https://cloud.githubusercontent.com/assets/12775748/21952722/1f163eb2-da67-11e6-8dbd-88dcc6f3e1f8.jpg)
![23-dymaxion](https://cloud.githubusercontent.com/assets/12775748/21952723/1f165cc6-da67-11e6-933f-5fd5f235b58c.jpg)
![24-dymaxion](https://cloud.githubusercontent.com/assets/12775748/21952724/1f1b61c6-da67-11e6-9719-41669ca2b99a.jpg)
![25-dymaxion](https://cloud.githubusercontent.com/assets/12775748/21952726/1f3439c6-da67-11e6-8e8c-fa9fefdaebfd.jpg)
![27-dymaxion](https://cloud.githubusercontent.com/assets/12775748/21952725/1f33a060-da67-11e6-9f2f-c757efa1f247.jpg)
![28-dymaxion](https://cloud.githubusercontent.com/assets/12775748/21952727/1f3478d2-da67-11e6-9143-7406557cbfac.jpg)
![29-dymaxion](https://cloud.githubusercontent.com/assets/12775748/21952729/1f3729d8-da67-11e6-87fe-d3fe10a81239.jpg)
![30-dymaxion](https://cloud.githubusercontent.com/assets/12775748/21952728/1f36cb82-da67-11e6-8308-ca7914e1d2e6.jpg)
![31-dymaxion](https://cloud.githubusercontent.com/assets/12775748/21952730/1f427e0a-da67-11e6-9fcb-b3b48b76aecb.jpg)


#### 맺음말

본 Stop Motion 촬영을 위한 기계는, 클레이 에니메이션 촬영을 위한 전용의 장치로서 제작되었다.  최초에 의도한 단기간/저비용으로 실용성있는 장치를 제작하는 목표에는 어느정도 근접하였다고 생각된다.  그러나 아직 사용되어 보지 못하여 그 유용성을 검증받지는 못한 상태이다.  실제 현장에서 사용될때 예상되는 문제점에 대한 검토는 물론 있었으나 충분치 못하다고 믿어지므로 지속적인 관리와 개선이 요구된다고 생각한다.

#### 감사의 말

제작과정에 다음의 분들에게 특히 도움과 격려를 받았습니다.

* 아낌없는 배려와 관심을 보여주신 곽문규 교수님
* 모든 지원을 아끼지 않으신 이미지 플러스의 정원만 사장님
* 세부적인 부분까지 일일이 챙겨주신 신일진 차장님
* 기회가 되도록 해 주신 서명석 형님
* 많은 조언과 편의를 봐 주신 실험실의 허석 선배님
* 공용공작실의 하동규 기사님
* 함께 작업한 Kart의 후배들
* 고향에서 아들걱정하시는 부모님과 가족들
* 사랑하는 여자친구 진섭이
* 함께 작업한 충실한 명일이
* 까다로운 작업을 끝까지 받아주신 형제기공사 사장님

#### 보고서

* [가계부-5679.pdf](https://drive.google.com/open?id=0B3VzdmodvgcIS0ZZaHpqNmJzbHc)
* [견적서-6070.pdf](https://drive.google.com/open?id=0B3VzdmodvgcIRkZndUgybnNpT2s)
* [서명석형-8384.pdf](https://drive.google.com/open?id=0B3VzdmodvgcIeW1xeXNxRVRNYXM)
* [앰프연결도큐멘테이션.pdf](https://drive.google.com/open?id=0B3VzdmodvgcIQWhEMllEb2h6RVk)
* [이미지플러스.pdf](https://drive.google.com/open?id=0B3VzdmodvgcIM1pyUzNSUTVUckU)
* [이미지플러스가계부.pdf](https://drive.google.com/open?id=0B3VzdmodvgcISkxFVEp6NV9PSlU)
* [MEDIART.pdf](https://drive.google.com/open?id=0B3VzdmodvgcIOFpaWmRCQ0VNcFE)
* [PROJECT1.pdf](https://drive.google.com/open?id=0B3VzdmodvgcIbF9kUmktc3NkQ3c)
* [PROJECT2.pdf](https://drive.google.com/open?id=0B3VzdmodvgcIdFNNbm9YNmctM2s)
* [SFX-4729.pdf](https://drive.google.com/open?id=0B3VzdmodvgcIcGZpeXRQay11ZGM)


#### 논문
* [논문계획.pdf](https://drive.google.com/open?id=0B3VzdmodvgcIZmhNdWhyQUZtdFU)
* [표지.pdf](https://drive.google.com/open?id=0B3VzdmodvgcIYnlkZkRqdWJNcTg)
* [차례.pdf](https://drive.google.com/open?id=0B3VzdmodvgcIQkdUal9MNEFyVzg)
* [본문.pdf](https://drive.google.com/open?id=0B3VzdmodvgcIS2VoRlBsam9JdG8)


## 6-DOF Motion Control

![_ -dymaxion](https://cloud.githubusercontent.com/assets/12775748/21952762/4ae1cbb0-da67-11e6-9cfc-8c11552fcb8a.jpg)
![_ -dymaxion](https://cloud.githubusercontent.com/assets/12775748/21952763/4b1ea77e-da67-11e6-842e-85b3a2a5d591.jpg)
![_ -dymaxion](https://cloud.githubusercontent.com/assets/12775748/21952764/4b1f02b4-da67-11e6-9eef-6005be479e74.jpg)
