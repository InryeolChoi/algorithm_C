# 레드블랙 트리란?
## 🌳 Red-Black Tree 정리

레드-블랙 트리는 자가 균형 이진 탐색 트리(Self-balancing Binary Search Tree) 중 하나임.
대표적으로 Java TreeMap, TreeSet, C++ map, set 내부 구현에 사용됨.

핵심 목적은 트리가 한쪽으로 치우쳐서 성능이 나빠지는 것을 방지하는 것임.

즉,
* 일반 BST → 최악 O(N)
* Red-Black Tree → 항상 O(log N)

⸻

# 1. 기본 개념

Red-Black Tree는 기본적으로 **Binary Search Tree(BST)** 이다.

BST의 규칙 노드에 색깔(red / black) 을 하나 추가한 BST임.

즉, 다음 규칙은 계속 유지됨.

왼쪽 서브트리 < 부모 노드 < 오른쪽 서브트리

```text
    10
   /  \
  5    20
```

하지만 일반 BST는 다음 문제가 있다.

```text
1 → 2 → 3 → 4 → 5
```

이렇게 삽입되면 트리가 **Linked List처럼 변형되어 O(N)** 이 된다.

이를 해결하기 위해 등장한 것이 **Balanced BST**이다.

대표적인 예

- AVL Tree
- Red-Black Tree

---

# 2. Red-Black Tree의 특징

Red-Black Tree는 **각 노드에 색상 정보를 추가한 BST**이다.

예시
```text
    10(B)
   /     \
 5(R)   20(R)
```
여기서

- B = Black
- R = Red


---

# 3. Red-Black Tree의 5가지 규칙

Red-Black Tree는 다음 **5개의 규칙을 항상 만족해야 한다.**

### 1. 모든 노드는 Red 또는 Black이다

각 노드는 반드시 하나의 색을 가진다.


### 2. Root 노드는 항상 Black이다.

### 3. 모든 Leaf(NIL)는 Black이다.

실제 구현에서는 **NULL 노드를 Black으로 간주한다.**

```
    10(B)
   /     \
 5(R)   20(R)
```
각 끝에는 보이지 않는 NIL 노드가 존재한다.

### 4. Red 노드의 자식은 반드시 Black이다

즉 **Red-Red가 연속으로 나타날 수 없다.**

잘못된 예
```
    10(B)
     /
   5(R)
   /
 3(R)
```

올바른 예
```
    10(B)
     /
   5(R)
   /
 3(B)
```

### 5. 모든 경로의 black 노드 수는 같음

루트에서 leaf까지 갈 때 black 노드 개수가 항상 동일

예
```
        10(B)
       /     \
    5(R)     20(R)
   /   \     /   \
 NIL  NIL  NIL   NIL
```

모든 경로
```
10 → 5 → NIL
10 → 20 → NIL
```
black 개수 동일


# 4. 왜 균형이 유지될까?

레드블랙 트리는 완벽한 균형은 아니지만 높이가 항상 제한됨

증명 결과: $\text{height} \le 2\log_{2}{(n+1)}$

즉 $O(\log N)$을 유지함.

# 5. 삽입 과정

삽입은 항상 red로 시작

왜냐면 black으로 넣으면 black depth가 깨질 가능성이 높기 때문.

## Step 1 : BST처럼 삽입
```
     10(B)
     /
   5(R)
```

## Step 2 : 규칙 위반 검사
주로 깨지는 규칙 : red-red
해결 방법 - 3가지 있음

1️⃣ Recoloring (색 변경)
2️⃣ Left Rotation
3️⃣ Right Rotation

# 6. 연산과정
| 연산 | 시간
| --- | ----
| Search | $O(\log N)$
| Insert | $O(\log N)$
| Delete | $O(\log N)$

# 7. 활용사례
* Java : Treemap, TreeSet
* C++ : std::map, std::set
* Linux Kernel : scheduler, memory management

