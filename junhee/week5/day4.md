# [7662-이중 우선순위 큐](https://www.acmicpc.net/problem/7662)

## 풀이

```cpp
#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n_input;
  cin >> n_input;  // T
  for (int i = 0; i < n_input; ++i) {
    int n_op;
    cin >> n_op;  // K
    multiset<int> s;
    for (int j = 0; j < n_op; ++j) {
      char op;
      int n;
      cin >> op >> n;
      if (op == 'I') {
        s.insert(n);
      } else if (!s.empty()) {
        if (n == 1) {
          s.erase(prev(s.end()));
        } else {
          s.erase(s.begin());
        }
      }
    }
    if (!s.empty()) {
      cout << *prev(s.end()) << " " << *s.begin();
    } else {
      cout << "EMPTY";
    }
    cout << '\n';
  }
  /*
  I n ; insert n
  D 1 ; delete max
  D -1 : delete min
  */

  return 0;
}
```

(복잡도 생략 가능)  
시간 복잡도 : $O(TK\log K)$  
공간 복잡도 : $O())$   


## 회고(지나치게 간단한 문제는 생략 가능)

### 간단한 풀이와 접근 방식

이중 우선순위 큐를 BST를 통해 구현한다.

### 왜 그러한 풀이를 했는지?

중복이 있을 수 있다는 것을 문제에서 설명하기 때문에 `multiset`을 사용한다

### (틀렸다면) 오답 원인



### (참고했다면) 참고한 코드


#### 왜 저 풀이를 떠올리지 못했을까?

# [1202-보석 도둑](https://www.acmicpc.net/problem/1202)

## 풀이

```cpp
#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> jewel(n);
  for (int i = 0; i < n; ++i) {
    int mass, value;
    cin >> mass >> value;
    jewel[i] = {value, mass};
  }
  sort(jewel.begin(), jewel.end());

  // cout << "JEWEL\n";
  // for (auto elem : jewel) {
  //   cout << "(" << elem.first << ", " << elem.second << ")\n";
  // }

  multiset<int> bag_capacity;
  for (int i = 0; i < k; ++i) {
    int c;
    cin >> c;
    bag_capacity.insert(c);
  }
  // cout << "BAG\n";
  // for (auto elem : bag_capacity) {
  //   cout << elem << '\n';
  // }
  long long ret = 0;

  for (auto i = jewel.end() - 1; i >= jewel.begin(); --i) {
    int mass, value;
    tie(value, mass) = *i;
    auto bag_it = bag_capacity.lower_bound(mass);
    if (bag_it == bag_capacity.end()) continue;
    ret += value;
    bag_capacity.erase(bag_it);
  }

  cout << ret;

  return 0;
}
```

(복잡도 생략 가능)  
시간 복잡도 : $O()$  
공간 복잡도 : $O()$   



## 회고(지나치게 간단한 문제는 생략 가능)

### 간단한 풀이와 접근 방식

그리디 + 이진 탐색 트리

### 왜 그러한 풀이를 했는지?

대소 관계가 필요하고, 삽입 삭제가 빈번하게 일어나면 `set, map`등을 사용한다.

### (틀렸다면) 오답 원인


### (참고했다면) 참고한 코드

#### 왜 저 풀이를 떠올리지 못했을까?

