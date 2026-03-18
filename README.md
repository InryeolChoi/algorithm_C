# algo_c

이 저장소는 알고리즘과 자료구조를 직접 구현하면서 다시 익히기 위한 C 학습 기록이다.  
단순히 개념만 읽는 대신, 손으로 구현하고 실행해 보면서 동작 원리와 자료구조의 형태를 정확히 이해하는 것을 목표로 한다.

## 왜 알고리즘을 배우는가

알고리즘은 문제를 푸는 절차를 설계하는 방법이고, 자료구조는 데이터를 어떤 형태로 관리할지 결정하는 방법이다.  
둘을 함께 익히면 다음 감각을 키울 수 있다.

- 같은 문제라도 더 빠르고 덜 복잡한 방법을 고르는 기준
- 시간 복잡도와 공간 복잡도를 실제 코드로 체감하는 경험
- 라이브러리나 프레임워크 뒤에서 어떤 구조가 동작하는지 이해하는 시야
- 구현 세부 사항 때문에 발생하는 버그를 추적하는 능력

결국 알고리즘 공부는 코딩 테스트 대비만이 아니라, 코드를 더 정확하게 읽고 더 납득 가능한 방식으로 설계하는 훈련에 가깝다.

## 왜 C로 구현하는가

이 저장소를 C로 작성한 이유는 자료구조의 내부 동작을 가장 직접적으로 다룰 수 있기 때문이다.

- 포인터를 통해 노드 연결 구조를 명확하게 볼 수 있다.
- 메모리 할당과 해제를 직접 관리하면서 자료구조의 생명주기를 이해할 수 있다.
- 표준 라이브러리에 많이 가려지지 않아 알고리즘의 핵심 로직이 드러난다.
- 다른 언어로 옮겨 가더라도 기반 원리를 단단하게 잡을 수 있다.

즉, C는 편의성이 높은 언어는 아니지만, 알고리즘과 자료구조를 "어떻게 돌아가는지"까지 공부하기에는 매우 좋은 선택이다.

## 이 저장소에 들어 있는 내용

현재 저장소는 정렬, 탐색, 트리 자료구조를 중심으로 예제를 모아 두고 있다.

### 정렬

- [bubble_sort](/Users/inchoi/algo_c/bubble_sort/README.md): 버블 정렬
- [insert_sort](/Users/inchoi/algo_c/insert_sort/README.md): 삽입 정렬
- [quicksort](/Users/inchoi/algo_c/quicksort/README.md): 기본 퀵 정렬
- [quicksort2](/Users/inchoi/algo_c/quicksort2/README.md): C 표준 라이브러리 `qsort` 사용 예제
- [quicksort3](/Users/inchoi/algo_c/quicksort3/README.md): 다른 파티션 방식의 퀵 정렬

### 탐색

- [binary_search](/Users/inchoi/algo_c/binary_search/README.md): 정렬된 배열에서의 이진 탐색

### 트리 / 자료구조

- [binary_search_tree](/Users/inchoi/algo_c/binary_search_tree/README.md): 기본 이진 탐색 트리
- [red_black_tree](/Users/inchoi/algo_c/red_black_tree/README.md): 자가 균형 이진 탐색 트리
- [b_tree](/Users/inchoi/algo_c/b_tree/README.md): B-Tree 개념 정리

## 학습 방식

이 저장소의 각 폴더는 보통 다음 요소 중 일부를 포함한다.

- 알고리즘 구현 `.c` 파일
- 필요한 헤더 파일
- 간단히 실행할 수 있는 `Makefile`
- 해당 알고리즘 설명용 `README.md` 또는 `ALGORITHM.md`

가능하면 각 구현은 "실제로 돌아가는 최소 예제" 형태를 유지하려고 한다.  
복잡한 프레임워크나 외부 의존성 없이, 알고리즘 그 자체에 집중하는 구성을 우선한다.

## 앞으로 다룰 방향

현재는 기초 정렬과 탐색, 트리 중심이지만 이후에는 다음 범위로 확장할 수 있다.

- 힙과 우선순위 큐
- 해시 테이블
- 그래프 탐색
- 동적 계획법
- 문자열 알고리즘

## 실행

대부분의 폴더는 독립적으로 빌드할 수 있다.

```bash
cd <algorithm-directory>
make
```

실행 파일 이름과 사용 방법은 각 폴더의 README를 보면 된다.
