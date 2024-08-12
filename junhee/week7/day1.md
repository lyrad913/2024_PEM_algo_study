# [1753-최단경로](https://www.acmicpc.net/problem/1753)

## 풀이

```cpp
#include <bits/stdc++.h>

using namespace std;
using graph = vector<vector<pair<int, int>>>;

const int INF = 4000000;

vector<int> dist;
graph g;  // g[src] = (weight, dist)

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int v, e;
  cin >> v >> e;
  g.resize(v + 1);
  dist.resize(v + 1);
  fill(dist.begin(), dist.end(), INF);
  int src;
  cin >> src;

  for (int i = 0; i < e; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({w, v});
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;

  dist[src] = 0;
  pq.push({0, src});
  while (!pq.empty()) {
    int here_weight, here_vertex;
    tie(here_weight, here_vertex) = pq.top();
    pq.pop();
    for (auto there : g[here_vertex]) {
      int there_weight, there_vertex;
      tie(there_weight, there_vertex) = there;
      if (dist[there_vertex] > dist[here_vertex] + there_weight) {
        dist[there_vertex] = dist[here_vertex] + there_weight;
        pq.push({dist[there_vertex], there_vertex});
      }
    }
  }
  for (int i = 1; i < v + 1; ++i) {
    if (dist[i] == INF)
      cout << "INF";
    else
      cout << dist[i];
    cout << '\n';
  }

  return 0;
}
```

(복잡도 생략 가능)  
시간 복잡도 : $O(E\log E)$  
공간 복잡도 : $O()$   



## 회고(지나치게 간단한 문제는 생략 가능)

### 간단한 풀이와 접근 방식

다익스트라 알고리즘의 구현

### 왜 그러한 풀이를 했는지?

음수 간선이 없다?

### (틀렸다면) 오답 원인



### (참고했다면) 참고한 코드

#### 왜 저 풀이를 떠올리지 못했을까?

