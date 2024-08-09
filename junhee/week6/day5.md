# [1197-최소 스패닝 트리](https://www.acmicpc.net/problem/1197)

## 풀이

```cpp
#include <bits/stdc++.h>

using namespace std;

int v, e;
vector<tuple<int, int, int>> edge;

vector<int> p(10005, -1);

int find(int x) {
  if (p[x] < 0) return x;
  return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v) {
  u = find(u);
  v = find(v);
  if (u == v) return false;
  if (p[u] == p[v]) p[u]--;
  if (p[u] < p[v])
    p[v] = u;
  else
    p[u] = v;
  return true;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> v >> e;

  for (int i = 0; i < e; ++i) {
    int a, b, cost;
    cin >> a >> b >> cost;
    edge.push_back({cost, a, b});
  }
  sort(edge.begin(), edge.end());
  int cnt = 0, ans = 0;
  for (int i = 0; i < e; ++i) {
    int a, b, cost;
    tie(cost, a, b) = edge[i];
    if (is_diff_group(a, b)) {
      ans += cost;
      cnt++;
    }
    if (cnt == v - 1) break;
  }

  cout << ans;

  return 0;
}
```

(복잡도 생략 가능)  
시간 복잡도 : $O()$  
공간 복잡도 : $O()$   



## 회고(지나치게 간단한 문제는 생략 가능)

### 간단한 풀이와 접근 방식

최소 신장 트리를 구하는 크루스칼 알고리즘 따라 연습해보기.   
union-find 알고리즘이 흥미로웠다.

### 왜 그러한 풀이를 했는지?



### (틀렸다면) 오답 원인



### (참고했다면) 참고한 코드


#### 왜 저 풀이를 떠올리지 못했을까?

