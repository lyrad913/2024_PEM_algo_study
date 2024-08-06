# [1927-최소 힙](https://www.acmicpc.net/problem/1927)

## 풀이

```cpp
#include <bits/stdc++.h>

using namespace std;

class m_heap {
  int _size = 0;
  vector<int> _m;

 public:
  m_heap() { _m = vector<int>(100000); }
  int pop() {
    if (_size == 0) return 0;
    int ret_value = _m[1];
    _m[1] = _m[_size--];
    int idx = 1;
    while (2 * idx <= _size) {
      int left_child = 2 * idx, right_child = 2 * idx + 1;
      int min_child = left_child;
      if (right_child <= _size && _m[right_child] < _m[left_child]) {
        min_child = right_child;
      }
      if (_m[idx] <= _m[min_child]) break;
      swap(_m[idx], _m[min_child]);
      idx = min_child;
    }
    return ret_value;
  }

  void insert(int x) {
    _m[++_size] = x;
    int idx = _size;
    while (idx != 1) {
      int parent = idx / 2;
      if (_m[parent] <= _m[idx]) break;
      swap(_m[parent], _m[idx]);
      idx = parent;
    }
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  m_heap mh;

  for (int i = 0; i < n; ++i) {
    int x_i;
    cin >> x_i;
    if (x_i == 0) {  // pop and print
      cout << mh.pop() << '\n';
    } else {  // insert
      mh.insert(x_i);
    }
  }

  return 0;
}
```

(복잡도 생략 가능)  
시간 복잡도 : $O()$  
공간 복잡도 : $O()$   



## 회고(지나치게 간단한 문제는 생략 가능)

### 간단한 풀이와 접근 방식

간단한 최소 힙 구현 문제

### 왜 그러한 풀이를 했는지?



### (틀렸다면) 오답 원인



### (참고했다면) 참고한 코드


#### 왜 저 풀이를 떠올리지 못했을까?

