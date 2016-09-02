## 창의적공학설계
- 금요일 1시~5시
- 엄현상
- dcslab.snu.ac.kr/courses/2016f/project
---

## 일정
10/28 중간발표 - 상세 스팩??

10/21 1시~2시 노르웨이 회사 소개

11월 회사 방문 - 삼성? LG? 네이버? SK CNC?

12/16 최종발표
---
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






