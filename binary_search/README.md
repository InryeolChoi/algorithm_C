# Binary Search

## 개요

이진 탐색(Binary Search)은 **정렬된 배열**에서 원하는 값을 빠르게 찾는 알고리즘이다.  
탐색 범위를 절반씩 줄여 가기 때문에 선형 탐색보다 훨씬 효율적이다.

## 이 폴더의 구현

이 구현은 [`BinarySearch.c`](/Users/inchoi/algo_c/binary_search/BinarySearch.c)에서 `Point` 배열을 정렬한 뒤, `point` 값을 기준으로 원하는 데이터를 찾는다.  
데이터 구조는 [`Point.h`](/Users/inchoi/algo_c/binary_search/Point.h)에 정의되어 있다.

```c
typedef struct tagPoint {
    int     id;
    double  point;
} Point;
```

실행 흐름은 다음과 같다.

1. `Dataset` 배열을 `qsort()`로 오름차순 정렬한다.
2. `BinarySearch()`가 `left`, `right`, `mid`를 이용해 탐색 구간을 줄인다.
3. 목표값과 같은 `point`를 찾으면 해당 원소의 주소를 반환한다.
4. 끝까지 찾지 못하면 `NULL`을 반환한다.

## 동작 원리

중간 인덱스 `mid`를 기준으로 값을 비교한다.

- 목표값이 더 크면 오른쪽 절반만 다시 탐색
- 목표값이 더 작으면 왼쪽 절반만 다시 탐색
- 같으면 탐색 종료

이 과정을 반복하면 매 단계마다 후보 개수가 절반으로 줄어든다.

## 시간 복잡도

- 정렬: `O(n log n)`
- 탐색: `O(log n)`

이미 정렬된 배열이 주어지면 탐색 자체는 `O(log n)`이다.

## 빌드와 실행

```bash
make
./binary_search
```

## 주의할 점

- 이진 탐색은 반드시 정렬된 데이터에서만 올바르게 동작한다.
- 현재 예제는 `double` 값을 `==`로 비교하므로, 일반적인 실수 연산에서는 오차 처리가 필요할 수 있다.
