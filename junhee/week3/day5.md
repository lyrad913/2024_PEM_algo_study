# [15683-감시](https://www.acmicpc.net/problem/15683)

신난다! 풀었다!

## 풀이

```cpp
#include <bits/stdc++.h>

using namespace std;

using Office = vector<vector<int>>;

using CctvDir = vector<vector<int>>;

CctvDir cctv1 = {{1, 0, 0, 0},
                 {0, 1, 0, 0},
                 {0, 0, 1, 0},
                 {0, 0, 0, 1}};
CctvDir cctv2 = {{1, 1, 0, 0},
                 {0, 0, 1, 1}};
CctvDir cctv3 = {{1, 0, 1, 0},
                 {1, 0, 0, 1},
                 {0, 1, 1, 0},
                 {0, 1, 0, 1}};
CctvDir cctv4 = {{1, 1, 1, 0},
                 {1, 1, 0, 1},
                 {1, 0, 1, 1},
                 {0, 1, 1, 1}};
CctvDir cctv5 = {{1, 1, 1, 1}};

int n, m; // 1<= n, m <=8
Office office;
Office office_copy;
vector<pair<int, int>> cctv_pos;

void init(){
  cin >> n >> m;

  office = Office(n, vector<int>(m));

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      cin >> office[i][j];
      if((1 <= office[i][j]) && (office[i][j] <= 5))
        cctv_pos.push_back({i, j});
    }
  }

  office_copy = office;
}

int count_zero(){
  int ret = 0;
  for(const auto& row: office_copy){
    for(const auto& elem: row){
      if(elem == 0) ++ret;
    }
  }
  return ret;
}

int min_zero = 987654321;

void up(const pair<int, int>& pos, int fill){
  int here_y = pos.first+1, here_x = pos.second;
  while(0 <= here_y && here_y < n && office_copy[here_y][here_x] != 6){
    office_copy[here_y++][here_x] += fill;
  }
}
void down(const pair<int, int>& pos, int fill){
  int here_y = pos.first-1, here_x = pos.second;
  while(0 <= here_y && here_y < n && office_copy[here_y][here_x] != 6){
    office_copy[here_y--][here_x] += fill;
  }
}
void left(const pair<int, int>& pos, int fill){
  int here_y = pos.first, here_x = pos.second-1;
  while(0 <= here_x && here_x < m && office_copy[here_y][here_x] != 6){
    office_copy[here_y][here_x--] += fill;
  }
}
void right(const pair<int, int>& pos, int fill){
  int here_y = pos.first, here_x = pos.second+1;
  while(0 <= here_x && here_x < m && office_copy[here_y][here_x] != 6){
    office_copy[here_y][here_x++] += fill;
  }
}

void (*fills[4])(const pair<int, int>&, int) = {up, down, left, right};

void mark(const pair<int, int>& pos, const vector<int>& view, int fill){
  for(int i = 0; i < 4; ++i){
    if(view[i] == 1){
      fills[i](pos, fill);
    }
  }
}
void unmark(const pair<int, int>& pos, const vector<int>& view, int unfill){
  for(int i = 0; i < 4; ++i){
    if(view[i] == 1){
      fills[i](pos, unfill);
    }
  }
}

void solve(int n){
  if(n == cctv_pos.size()){
    int ret = count_zero();
    min_zero = min(ret, min_zero);
    return;
  }
  auto cctv = office[cctv_pos[n].first][cctv_pos[n].second];
  switch (cctv)
  {
  case 1:
    for(int i = 0; i < cctv1.size(); ++i){
      mark(cctv_pos[n], cctv1[i], 7);
      solve(n+1);
      unmark(cctv_pos[n], cctv1[i], -7);
    }
    break;
  case 2:
    for(int i = 0; i < cctv2.size(); ++i){
      mark(cctv_pos[n], cctv2[i], 8);
      solve(n+1);
      unmark(cctv_pos[n], cctv2[i], -8);
    }
    break;
  case 3:
    for(int i = 0; i < cctv3.size(); ++i){
      mark(cctv_pos[n], cctv3[i], 9);
      solve(n+1);
      unmark(cctv_pos[n], cctv3[i], -9);
    }
    break;
  case 4:
    for(int i = 0; i < cctv4.size(); ++i){
      mark(cctv_pos[n], cctv4[i], 10);
      solve(n+1);
      unmark(cctv_pos[n], cctv4[i], -10);
    }
    break;
  case 5:
    for(int i = 0; i < cctv5.size(); ++i){
      mark(cctv_pos[n], cctv5[i], 11);
      solve(n+1);
      unmark(cctv_pos[n], cctv5[i], -11);
    }
    break;
  default:
    break;
  }
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  init();
  solve(0);
  cout << min_zero;
}
```

아마도... 시간 복잡도는 $O(4^knm)$

k: cctv 개수
n, m : 사무실 가로세로

## 회고(지나치게 간단한 문제는 생략 가능)

보자마자 든 생각 : 무식하게 풀어야겠는데..?

참 이것저것 많이도 썼다. 함수 포인터도 쓰고.. 타입 정의도 쓰고...

### 간단한 풀이와 접근 방식

하나씩 놓았다가 돌려봤다 해보자! :arrow_right: 각 cctv마다 여러 상태를 해봐야하니 dfs와 유사한 접근법을 취해야겠다.

그 다음부터는 노가다. 조금 더 우아하게 풀 수는 없나? 시험장에서 이보다 빨리 풀 수는 없나? 가 질문. 해설을 확인해봐야겠다.

### 주의할 지점

1. 단순히 지운다고 0으로 설정해버리면, 다른 cctv가 감시하는 구역도 없애서 개수에 차이가 생길 수 있음, 더하고 빼는 형식이 적당해 보였다.
2. 변수는 선언할 때 무조건 초기화하자. `count_zero`에서 `ret`을 초기화안해서 문제가 있었다.
3. void 형을 반환하더라도 항상 base condition에서는 return을 까먹지 말자. 아래도 우르르 실행된다. 무한재귀가 발생한다.

### 확인할 해설

1. [강의](https://blog.encrypted.gg/948)