## 창의적공학설계
- 금요일 1시~5시
- 엄현상
- dcslab.snu.ac.kr/courses/2016f/project


## 일정
10/28 중간발표 - 상세 스팩??

10/21 1시~2시 노르웨이 회사 소개

11월 회사 방문 - 삼성? LG? 네이버? SK CNC?

12/16 최종발표


## 회사 과제 설명  
삼성전자 생산기술연구소  
- ``Long time Process Data Visualization``  
  반도체 설비로부터 취합된 센서 data를 DB로 부터 읽음  
  읽은 센서 시계열 data를 point로 변환하고, 선으로 연결하여 도식화된 차트 생성  
  (최적화된 그래프 추출식 && 알고리즘 제안)  
  부분 확대, 축소 기능 개발  
  그래프 손실 없어야 하고, 확대했을 때 곡률 잘 보여야...  
  어렵다고 합니다...  
  필요 지식 : 대용량 데이터 처리, visualization & DB, 데이터 입출력  
  유사 알고리즘 : 등고선 알고리즘  
  언어 자유  
  그래프 기대 스팩 시간 : 수 초...  

- ``Big Data 기법을 활용한 Photo 설비 data`` - 품질 연계성 분석  
  많은 공정 데이터 중에서 원인 조합을 분석하는 알고리즘 구현  
  설비 log data 적재/분석을 위한 big data 플랫폼 아키텍처 개념도 및 설명  
  답이 없으니 우리의 창의성으로...  
  RDBMS 사용은 지양...  
  통계 분석 및 시각화 업무가 주로 이루어지는 시스템  
  하둡 기반  
  두개 이상의 원인 인자 조합 알고리즘을 고민해보고 조사해볼것  
  알고리즘을 신규로 개발하지 않아도 OK  
  이미 존재하는 알고리즘을 두가지 이상 구현해 볼 것  
  주어진 데이터 조합 중 가 장 의미있는 조합을 찾아볼 것  
  머신러닝 오픈소스 상관없음  

- ``자동 빌드 & 배포 & 업데이트 시스템``  
  Jira Jenkins  
  네트워크에 연결된 프로그램 배포 서버 별 버전 자동 동기화  
  Jenkins 인터페이스를 이용한 빌드  
  버전 별 자동 백업 및 롤백 기능  
  서버 배포 히스토리 관리  
  one-click 배포(URL 호출을 통한 프로그램 설치)  
  End-User 단 install/update Application 개발  
  최신 버전 알림 기능  

삼성전자 소프트웨어 센터(타이젠 할 것이다...)  
- ``ARTIK 활용 Tizen Framework 및 IoT 시나리오 개발``  
  GPIO API 개발..(앱 개발자가 사용할 수 있게)  
  필요지식: Kernel, GPIO, 네트워크, 시프, HTML5, 자바스크립트(node.js)  

SK CNC  
- ``Intelligent Cloud Auto Scaler``  
  Cloud 내의 자원을 효율적으로 관리/분배하는 것이 핵심 기술  
  Cloud Foundry의 인스턴스를 부하에 따라 증가/감소시키는 Auto Scaler 기능개발  
  Cloud 자원 조율 연구 조사 및 분석  
  CPU, Memory, Throughput 등 다양한 Metric Collect 구현  
  다양한 Policy 기반의 스케줄링 구현  
  워크로드 분석 통한 지능형 스케줄링 엔진 개발  

- ``Big Data analytics as a Service``  
  big data analytics를 클라우드 환경에서 구축  
  Multi-cloud 환경에서 동작하는 open source 기반  
  cloud 기반 bnig data 솔루션 사례 조사 분석  
  openStack sahara를 cloud 환경에 구축  
  Docker 기반의 Hadoop Cluster 컨테이너 구성  
  각 Cluster간 Multi-Tenant 보안 아키텍처 적용  

- ``Flash-Based Cloud Storage``  
  Ceph file system 의 구조 및 Scalability 분석  
  OpenStack 설치 및 Ceph file system 구축  
  다양한 Cloud Worklad 대상 성능 분석 및 최적화  
  HDD 및 Flash Disk 특성별 Ceph 성능 최적화  

컴투스  
- ``스마트폰 VR 게임을 위한 인터랙션 연구``  
  리소스를 제공해주고, 어떤 식으로 구현 할 수 있을지 이야기해보자  
  VR 게임 개발..?

- ``컴투스 대표게임 스마트폰으로 이식``  
  관련 특정 게임의 로직을 스마트폰에 이식...  
  코드를 다 주지는 않는다.  

fuse (노르웨이 회사! 크로스플랫폼 앱 개발 UX tool 제공)
- ``app 하나 만들어야 한다.``  
  재미있겠는데?  

소프트캠프(보안소프트웨어 회사)  
- ``악성의심문서의 구조 분석 및 재구성``  
  오픈소스 문서변환 라이브러리를활용한 악성의심문서 분석  
  오픈소스 문서변환 라이브러리 리서치 및 CVE취약점 문서 리서치  
  오픈소스 문서변환 라이브러리를 이용한 악성의심문서 컨텐츠 추출  
  컨텐츠 재구성  
  C++ 이나 C# 사용...  
  제품 적용까지 목표로 두고 있음  

캐스트이즈  
- ``앱 요청 푸시 시스템 개발``  
  Google GCM이나 Apple APNs 이용해서 만듬.  
  전송 결과 및 리포트  
  API, XML/JSON/REST 지식  
  Java 잘 써야 한다..!  

- ``실시간 경매 시스템(Real-Time Bidding)``  
  광고주가 실시간 경매를 이용하여 인벤토리를 구매하는 자동화 시스템  
  openRTB 규격 기반으로 실시간 경매 시스템 개발  
  다양한 조건을 고려한 광고 청약 정보 처리  
  복합 조건에서의 실시간 결정 시스템  
  집행 서버/결정 서버 연동 등의 방법으로 고아고 및 사용자에 대한 집게, 통계, 리포팅  
  Java, Web API 개발 관련 지식  
  Real-Time 초고속 처리 기술  

태진인포텍(국산 서버와 storage.. 반도체를 만듬)  
- ``시스템 내 data 저장장치 의 성능측정 및 안정성 기법``  
  기존 벤치마크는 오차가 있고 안정성에 문제가 있다.  
  윈도우 응용 프로그램 개발 능력 && C++  

- ``이기종 저장장치 사이의 데이터 이동 및 저장 방법``  
  어렵다.... DRAM SSD, Flash SSD, HDD에 저장되는 데이터를 관리  
  Auto 티어링 시스템  
  기존 오픈소스는 2티어인데, 3티어를 만들어 달라.  

- ``메모리 데이터 무결성 유지를 위한 데이터 관리방한 연구``
  FPGA 설계.............  
  verilog(VHDL)  
  Altera 시스템 툴...  

티맥스소프트  
- ``Heuristic을 이용한 스도쿠 문제 출제 및 풀이기``  
  출제프로그램: 임의의 정사각행렬로 확장.  
  해결프로그램: 빠른 시간내에...  
  가능할 경우 분산 처리 방식으로 구현..  
  캐시까지 고려하라고..?  
  언어는 무관  

- ``openCV 이용한 gender classification``  
  주어진 얼굴 이미지 DB를 통해 성별을 구분할 attribute 식별  
  머신러닝 알고리즘  
  KNN, SVM, Naive Bayes  등등등.... 
  하둡을 사용해서 최대한 많은 DB 제공...
  오픈소스를 써도 좋지만 가능한 한 직접 구현해봐라...  
  인종 관계 없이..?  그건 

- ``Event Loop 를 이용한 Web Engine 개발``  
  event loop를 이용해 간단한http요청을 처리할 수 있는 웹 엔진 개발  
  event 구조를 설계하고 vent loop와 worker thread간에 통신 기능 개발  
  java, servlet, db  

- ``simple syntax language interpreter 작성``
  c-like 언어에 대한 인터프리터 작성  
  알고리즘, 컴파일러 지식....  

네오위즈  
- `어프리케이션 통합 런쳐 개발`  
  배틀넷같은 통합 런처!  
  실질적인 코드 제공 불가  
  데모 아이템에 대한 관리를 일단 구현  

- `DNS 쿼리 패턴 분석을 통한 APT 공격탐지`  
  악성 리퀘스트 찾는거 하나, 감염된 호스트 특정하는 툴 하나  
  DNS Log 분석...  

SK 플레닛  
- `OCR by Deep Learning`  
  Optical Character Recognition(사진읽고 텍스트파일로 만든다.)  
  DB도 직접 만들어야 한다???  합성DB?  
  BLU 로 평가한다.  

아마존  (channyun@amazon.com)
- `Amazon Echo를 위한 Alexa 음성 인식 서비스 앱 개발(신규)`  
  AWS Lambda 및 dynmoDB등의 AWS 서비스를 통해 음성인식 앱 개발  
  음성 인식 앱 아이디어는 자유 주제이나, 주제가 없는 경우, Kpop Enabler 만들기  
  REST API나 JSON 호출 지식...  

- `Amazon DSSTNE 최적화된 딥러닝 클라우드 이미지 만들기(신규)`  
  AWS GPU 인스턴스 전용 이미지 및 샘플 프로젝트 제작  
  원 클릭 론칭용 클라우드 formation Template 구현  
  기존 벤치마킹 테스트와 대비한 성능 개선  
  DSSTNE 길잡이 역할...  

LG 전자  
- `W3C 웹 표준 기술을 활용한 웹 앱 개발`  
  이거 하면 나랑 맞긴 한데...  
  필수기술 5개 선택기술 3개  
  ```
  필수기술 : 1.presentation API
            2.media queries
            3.service worker
            4.push notification
            5.web app manifest

  선택기술 : 1.web components
            2.fetch API
            3.Background sync API
            4.perfomance timeline
            5.CSS flexible box layout
            6.CSS fonts
  ```
  이런 기술을 잘 보여주는 웹앱을 만들어야 한다.
