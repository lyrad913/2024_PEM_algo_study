# [4179-불!](https://www.acmicpc.net/problem/4179)

## 풀이

```cpp
#include <bits/stdc++.h>

using namespace std;

int dir = 4;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int rows, cols;
int here_x, here_y;
queue<pair<int, int>> fires;
char maze[1000][1000];
int escape_time[1000][1000] = {0, };
int fire_transfer_time[1000][1000] = {0, };

void init_maze(){
  cin >> rows >> cols;

  for(int i = 0 ; i < rows ; ++i){
    string tmp; cin >> tmp;
    for(int j = 0; j < cols ; ++j){
      maze[i][j] = tmp[j];
      escape_time[i][j] = -1;
      fire_transfer_time[i][j] = -1;
      if(maze[i][j] == 'J') {
        here_x = i;
        here_y = j;
        escape_time[i][j] = 0;
      }
      if(maze[i][j] == 'F'){
        fires.push({i, j});
        fire_transfer_time[i][j] = 0;
      }
    }
  }
}

bool is_escape(int x, int y){
  if(x < 0 || x >= rows || y < 0 || y >= cols) return true;
  else return false;
}

bool is_moveable(int x, int y){
  if(is_escape(x, y)) return false;
  return maze[x][y] == '.' ? true : false;
}


void transfer_fire(){
  while(!fires.empty()){
    pair<int, int> fire = fires.front(); fires.pop();
    for(int i = 0; i < dir; ++i){
      int there_x = fire.first + dx[i];
      int there_y = fire.second + dy[i];
      if(is_moveable(there_x, there_y) && fire_transfer_time[there_x][there_y] == -1){
        fire_transfer_time[there_x][there_y] = fire_transfer_time[fire.first][fire.second] + 1;
        fires.push({there_x, there_y});
      }
    }
  }
}

void escape(){
  queue<pair<int, int>> q; q.push({here_x, here_y});
  while(!q.empty()){
    pair<int, int> here = q.front(); q.pop();
    for(int i = 0; i < dir; ++i){
      int there_x = here.first + dx[i];
      int there_y = here.second + dy[i];
      if(is_escape(there_x, there_y)){
          cout << escape_time[here.first][here.second] + 1;
          return;
      }
      if(is_moveable(there_x, there_y) && escape_time[there_x][there_y] == -1){
        if((fire_transfer_time[there_x][there_y] > escape_time[here.first][here.second] + 1)
        || (fire_transfer_time[there_x][there_y] == -1)){
          escape_time[there_x][there_y] = escape_time[here.first][here.second] + 1;
          q.push({there_x, there_y});
        }
      }
    }
  }
  cout << "IMPOSSIBLE";
  return ;
}

int main(void){
  ios::sync_with_stdio;(false);
  cin.tie(nullptr);
  init_maze();
  transfer_fire();
  escape(); 
  return 0;
}
```

## 회고(지나치게 간단한 문제는 생략 가능)

### 간단한 풀이와 접근 방식

불 확산에 대한 BFS + 지훈이 탈출에 대한 BFS

### 왜 그러한 풀이를 했는지? 

왜 BFS가 떠올라야하나? 그래프스러운 입력 표현 + 출력에서 보이는 "가장 빠른" + 상하좌우로 퍼지는 등...

불이 먼저 확산되어도, 지훈이가 움직이는데에는 지장이 없다는 것을 파악했다.(문제 풀이 순서 강제)

우선은 한 레벨씩 불 퍼트리고, 지훈이 움직이고, 불 퍼트리고, 지훈이 움직이고 식으로 하려 했었다. 큐에서 꺼내서 하다보니 그러한 접근이 어려웠고, 일반적으로 사용하는 visited배열에 시간(거리) 정보를 저장하여 비교하는 식으로 대체할 수 있음을 깨달음.


### (틀렸다면) 오답 원인

visited배열(`escape_time`, `fire_transfer_time`)을 선언할 때, 별 생각 없이 그 윗줄의 `maze`배열을 보고 char형으로 선언함. 미로 길이가 1000이 최대기 때문에, char의 범위인 -128~127 으로는 커버가 안됨. 이거 때문에 2%에서 계속 틀리고 질문 게시판의 짧은 반례들로는 찾을 수가 없었음. 변수의 값 범위에 유의해야한다. 아니면 파이썬을 쓰든지...

### (참고했다면) 참고한 코드

#### 왜 저 풀이를 떠올리지 못했을까?
