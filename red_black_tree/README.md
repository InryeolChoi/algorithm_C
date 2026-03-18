# Red-Black Tree

## 개요

레드-블랙 트리는 색 정보를 추가해 균형을 유지하는 자가 균형 이진 탐색 트리이다.  
일반 BST는 삽입 순서에 따라 한쪽으로 치우쳐 최악의 경우 `O(n)`이 되지만, 레드-블랙 트리는 높이를 제한해 탐색, 삽입, 삭제를 `O(log n)`에 가깝게 유지한다.

## 이 폴더의 구현

자료구조와 함수 선언은 [`redblacktree.h`](/Users/inchoi/algo_c/red_black_tree/redblacktree.h), 구현은 [`redblacktree.c`](/Users/inchoi/algo_c/red_black_tree/redblacktree.c), 실행 예제는 [`main.c`](/Users/inchoi/algo_c/red_black_tree/main.c)에서 확인할 수 있다.

이 구현은 `Nil` 센티넬 노드를 사용한다.

- 모든 리프의 끝을 `NULL` 대신 `Nil`로 처리
- `Nil`은 항상 `BLACK`
- 회전과 삭제 보정 로직에서 경계 처리를 단순화

## 레드-블랙 트리 규칙

레드-블랙 트리는 다음 규칙을 유지해야 한다.

1. 모든 노드는 `RED` 또는 `BLACK`이다.
2. 루트는 `BLACK`이다.
3. 모든 `Nil` 리프는 `BLACK`이다.
4. `RED` 노드의 자식은 모두 `BLACK`이다.
5. 어떤 노드에서든 리프까지 가는 모든 경로의 black 노드 수는 같다.

이 규칙 덕분에 트리 높이가 과도하게 커지지 않는다.

## 주요 연산

### 탐색

탐색은 일반 BST와 동일하게 값 비교를 통해 왼쪽 또는 오른쪽으로 내려간다.

### 삽입

삽입은 세 단계로 진행된다.

1. `insertNodeHelper()`로 BST 위치에 새 노드를 연결
2. 새 노드를 `RED`로 두고 자식을 `Nil`로 설정
3. `rebuildAfterInsert()`에서 재색칠과 회전으로 규칙 복구

부모와 삼촌의 색 조합에 따라 다음 동작이 일어난다.

- 삼촌이 `RED`: 재색칠
- 삼촌이 `BLACK`이고 꺾인 형태: 1차 회전으로 일직선 정리
- 삼촌이 `BLACK`이고 일직선 형태: 2차 회전으로 균형 복구

### 삭제

삭제는 먼저 실제로 제거할 노드를 정한 뒤, `BLACK` 노드가 제거된 경우 `rebuildAfterRemove()`로 균형을 복구한다.  
삭제 보정에서는 형제 노드의 색과 형제 자식들의 색을 기준으로 회전과 재색칠을 수행한다.

## 시간 복잡도

- 탐색: `O(log n)`
- 삽입: `O(log n)`
- 삭제: `O(log n)`

## 빌드와 실행

```bash
make
./red_black_tree
```

## 예제 프로그램

[`main.c`](/Users/inchoi/algo_c/red_black_tree/main.c)는 메뉴 기반 CLI를 제공한다.

- 값 삽입
- 값 삭제
- 값 검색
- 트리 구조 출력

`printTree()`는 각 노드의 색과 black count를 함께 출력해서 균형 상태를 눈으로 확인할 수 있게 한다.

## 활용 사례

- `std::map`, `std::set` 같은 균형 탐색 트리 기반 컨테이너
- 정렬 상태를 유지한 검색 구조
- 빈번한 삽입/삭제가 있는 사전형 자료구조
