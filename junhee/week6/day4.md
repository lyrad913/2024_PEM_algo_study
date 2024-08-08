# [11725-트리의 부모 찾기](https://www.acmicpc.net/problem/11725)

## 풀이

```cpp
#include <bits/stdc++.h>

using namespace std;

using graph = vector<vector<int>>;

graph g;

vector<int> visited;
vector<int> parent;

void dfs(int here) {
  visited[here] = 1;
  for (int there : g[here]) {
    if (visited[there] == 0) {
      parent[there] = here;
      dfs(there);
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  g = graph(n + 1);
  parent = vector<int>(n + 1, 0);
  visited = vector<int>(n + 1, 0);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  dfs(1);

  for (auto i = parent.begin() + 2; i != parent.end(); ++i) {
    cout << *i << '\n';
  }

  return 0;
}
```

(복잡도 생략 가능)  
시간 복잡도 : $O(V)$  
공간 복잡도 : $O()$   

V : 정점의 개수

## 회고(지나치게 간단한 문제는 생략 가능)

### 간단한 풀이와 접근 방식

dfs

### 왜 그러한 풀이를 했는지?



### (틀렸다면) 오답 원인


### (참고했다면) 참고한 코드

#### 왜 저 풀이를 떠올리지 못했을까?

# [1991-트리의 순회](https://www.acmicpc.net/problem/1991)

## 풀이

```cpp
#include <bits/stdc++.h>

using namespace std;

vector<pair<char, char>> tree;

void init() {
  int n;
  cin >> n;
  tree.resize(n);
  for (int i = 0; i < n; ++i) {
    char p, lc, rc;
    cin >> p >> lc >> rc;
    tree[p - 'A'] = {lc, rc};
  }
}

void inorder(int here) {
  char lc, rc;
  tie(lc, rc) = tree[here];
  if (lc != '.') inorder(lc - 'A');
  cout << (char)(here + 'A');
  if (rc != '.') inorder(rc - 'A');
}

void postorder(int here) {
  char lc, rc;
  tie(lc, rc) = tree[here];
  if (lc != '.') postorder(lc - 'A');
  if (rc != '.') postorder(rc - 'A');
  cout << (char)(here + 'A');
}

void preorder(int here) {
  char lc, rc;
  tie(lc, rc) = tree[here];
  cout << (char)(here + 'A');
  if (lc != '.') preorder(lc - 'A');
  if (rc != '.') preorder(rc - 'A');
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  init();

  preorder(0);
  cout << '\n';
  inorder(0);
  cout << '\n';
  postorder(0);

  return 0;
}
```

(복잡도 생략 가능)  
시간 복잡도 : $O()$  
공간 복잡도 : $O()$   



## 회고(지나치게 간단한 문제는 생략 가능)

### 간단한 풀이와 접근 방식

ez

### 왜 그러한 풀이를 했는지?



### (틀렸다면) 오답 원인



### (참고했다면) 참고한 코드


#### 왜 저 풀이를 떠올리지 못했을까?

# [2252-줄 세우기](https://www.acmicpc.net/problem/2252)

## 풀이

```cpp
#include <bits/stdc++.h>

using namespace std;

using graph = vector<vector<int>>;

stack<int> ret;

void dfs(const graph& g, vector<int>& visited, int here) {
  for (int i = 0; i < g[here].size(); ++i) {
    int there = g[here][i];
    if (visited[there] == 0) {
      visited[there] = 1;
      dfs(g, visited, there);
    }
  }
  ret.push(here);
}

void dfsAll(const graph& g, vector<int>& visited) {
  for (int here = 1; here < g.size(); ++here) {
    if (visited[here] == 0) {
      visited[here] = 1;
      dfs(g, visited, here);
    }
  }
  while (!ret.empty()) {
    cout << ret.top() << " ";
    ret.pop();
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  graph g(n + 1);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
  }
  vector<int> visited(n + 1, 0);

  dfsAll(g, visited);

  return 0;
}
```

(복잡도 생략 가능)  
시간 복잡도 : $O(V+E)$  
공간 복잡도 : $O()$   

dfs의 역순 출력이니까 V+E겠지

## 회고(지나치게 간단한 문제는 생략 가능)

### 간단한 풀이와 접근 방식

위상 정렬은 dfs의 역순

### 왜 그러한 풀이를 했는지?



### (틀렸다면) 오답 원인



### (참고했다면) 참고한 코드

  
#### 왜 저 풀이를 떠올리지 못했을까?

