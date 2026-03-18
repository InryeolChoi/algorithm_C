# Binary Search Tree

## 개요

이진 탐색 트리(BST)는 각 노드가 최대 두 개의 자식을 가지며, 다음 규칙을 만족하는 트리이다.

- 왼쪽 서브트리의 모든 값 < 현재 노드 값
- 오른쪽 서브트리의 모든 값 > 현재 노드 값

이 규칙 덕분에 탐색, 삽입, 삭제를 트리 높이에 비례해 수행할 수 있다.

## 이 폴더의 구현

핵심 자료구조와 함수 선언은 [`binarySearchTree.h`](/Users/inchoi/algo_c/binary_search_tree/binarySearchTree.h)에 있고, 실제 구현은 [`binarySearchTree.c`](/Users/inchoi/algo_c/binary_search_tree/binarySearchTree.c)에 있다.  
예제 실행 코드는 [`test.c`](/Users/inchoi/algo_c/binary_search_tree/test.c)에서 확인할 수 있다.

구현된 주요 기능:

- 노드 생성과 트리 해제
- 값 탐색
- 최소값 노드 탐색
- 노드 삽입
- 노드 삭제
- 중위 순회 출력

## 주요 연산 설명

### 탐색

현재 노드와 목표값을 비교해서:

- 같으면 현재 노드 반환
- 목표값이 더 작으면 왼쪽 이동
- 목표값이 더 크면 오른쪽 이동

### 삽입

BST 규칙을 유지할 수 있는 위치까지 내려간 뒤 새 노드를 연결한다.

### 삭제

삭제는 세 가지 경우로 나뉜다.

1. 자식이 없는 노드: 바로 제거
2. 자식이 하나인 노드: 자식을 끌어올려 대체
3. 자식이 둘인 노드: 오른쪽 서브트리의 최소값 노드로 대체 후 삭제

현재 구현의 `removeNode()`도 이 전형적인 방식을 따른다.

## 순회

`InorderPrintTree()`는 중위 순회(inorder traversal)를 수행한다.  
BST를 중위 순회하면 값이 오름차순으로 출력된다.

## 시간 복잡도

- 평균 탐색: `O(log n)`
- 평균 삽입: `O(log n)`
- 평균 삭제: `O(log n)`
- 최악의 경우: `O(n)`

트리가 한쪽으로 치우치면 연결 리스트처럼 변할 수 있다는 점이 BST의 한계다.

## 빌드와 실행

```bash
make
./bs_tree
```

## 예제 프로그램

[`test.c`](/Users/inchoi/algo_c/binary_search_tree/test.c)에서는 다음 흐름을 실행한다.

- 여러 값을 트리에 삽입
- 특정 값 검색
- 중위 순회 결과 출력
- 값 `98` 삭제
- 값 `111` 재삽입

이 예제를 통해 BST의 기본 연산 흐름을 확인할 수 있다.
