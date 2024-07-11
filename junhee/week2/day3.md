# [1926-그림](https://www.acmicpc.net/problem/1926)

## 풀이

```cpp
#include <bits/stdc++.h>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int paper[501][501];
bool visited[501][501] = {false, };

int n, m; 

bool accessable(int x, int y){
  if(x < 0 || x >= n || y < 0 || y >= m) return false;
  if(visited[x][y] || paper[x][y] == 0) return false;
  return true; 
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  cin >> n >> m;

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      cin >> paper[i][j];
    }
  }
  
  int max_painting = 0;
  int n_painting = 0;
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      if(paper[i][j] == 0 || visited[i][j]) continue;
      ++n_painting;
      queue<pair<int, int> > q;
      visited[i][j] = true;
      q.push({i, j});
      
      int painting_size = 0;
      while(!q.empty()){
        ++painting_size;
        auto here = q.front(); q.pop();

        for(int dir = 0; dir < 4; ++dir){
          int there_x = here.first + dx[dir];
          int there_y = here.second + dy[dir];
          if(accessable(there_x, there_y)){
            visited[there_x][there_y] = true;
            q.push({there_x,there_y});
          }
        }
      }
      max_painting = max(painting_size, max_painting);
    }
  }
  cout << n_painting << '\n' << max_painting;
}
```

(복잡도 생략 가능)  

시간 복잡도 : O(nm)  

## 회고(지나치게 간단한 문제는 생략 가능)

### 간단한 풀이와 접근 방식

BFS를 활용한 탐색 문제

### 왜 그러한 풀이를 했는지? 

그래프가 보이면 우선 BFS, DFS를 떠올려야함. 테스트 케이스가 인접 행렬 방식으로 그래프를 표현햇으니 생각해봄직.

### (틀렸다면) 오답 원인

습관적으로 max값에 -1을 넣어두었는데, 최솟값이 0이 나올 수 있다는 사실을 간과했다. 

조심할 필요가 있어보인다.

### (참고했다면) 참고한 코드



#### 왜 저 풀이를 떠올리지 못했을까?
