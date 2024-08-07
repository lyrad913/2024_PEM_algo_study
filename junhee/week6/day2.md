# [11724-연결 요소의 개수](https://www.acmicpc.net/problem/11724)

## 풀이

```cpp
#include <bits/stdc++.h>

using namespace std;

using graph = vector<vector<int>>;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // init
  int n, m;
  cin >> n >> m;
  graph g;
  g.reserve(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  // solving
  queue<int> q;

  vector<int> visited(n, 0);

  int ret = 0;
  for (int i = 0; i < n; ++i) {
    if (visited[i] == 0) {
      q.push(i);
      visited[i] = 1;
      ++ret;
    }
    while (!q.empty()) {
      int here = q.front();
      q.pop();
      for (auto it = g[here].begin(); it != g[here].end(); ++it) {
        if (visited[*it] == 0) {
          q.push(*it);
          visited[*it] = 1;
        }
      }
    }
  }
  cout << ret;

  return 0;
}
```

(복잡도 생략 가능)  
시간 복잡도 : $O(n+m)$  
공간 복잡도 : $O()$   

n : 노드의 개수, m: 간선의 개수 

## 회고(지나치게 간단한 문제는 생략 가능)

### 간단한 풀이와 접근 방식

bfs/dfs를 돌리면 연결된 애들은 다 방문하니까, 처음에 방문안한 뭉텡이만 세어주면 된다

### 왜 그러한 풀이를 했는지?



### (틀렸다면) 오답 원인


### (참고했다면) 참고한 코드

#### 왜 저 풀이를 떠올리지 못했을까?

