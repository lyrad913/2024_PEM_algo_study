# [11494-플로이드](https://www.acmicpc.net/problem/11494)

## 풀이

```cpp
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> ret;  // ret[src][dest]
const int INF = 100000 * (99) + 1;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  ret = vector<vector<int>>(n, vector<int>(n, INF));
  for (int i = 0; i < n; ++i) {
    ret[i][i] = 0;
  }
  for (int i = 0; i < m; ++i) {
    int a, b, cost;
    cin >> a >> b >> cost;
    ret[a - 1][b - 1] = min(ret[a - 1][b - 1], cost);
  }
  for (int k = 0; k < n; ++k) {
    for (int src = 0; src < n; ++src) {
      for (int dest = 0; dest < n; ++dest) {
        ret[src][dest] = min(ret[src][dest], ret[src][k] + ret[k][dest]);
      }
    }
  }
  for (auto elem : ret) {
    for (auto e : elem) {
      if (e == INF) e = 0;
      cout << e << " ";
    }
    cout << "\n";
  }

  return 0;
}
```

(복잡도 생략 가능)  
시간 복잡도 : $O(V^3)$  
공간 복잡도 : $O()$   

v : 정점의 개수(여기서는 도시)

## 회고(지나치게 간단한 문제는 생략 가능)

### 간단한 풀이와 접근 방식

플로이드 알고리즘 구현해보기

### 왜 그러한 풀이를 했는지?



### (틀렸다면) 오답 원인

무수한 맞왜틀. 최댓값을 설정할 때는, `가능한 변수의 가장 큰 값 + 1`이 아니라 `가능한 가장 큰 답의 값 + 1`을 해줘야 한다....

### (참고했다면) 참고한 코드

#### 왜 저 풀이를 떠올리지 못했을까?

