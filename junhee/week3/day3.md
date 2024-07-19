# [15683-감시](https://www.acmicpc.net/problem/15683)

유형 : 시뮬레이션. 너무 복잡하다. 푸는 중

## 풀이

```cpp
#include <bits/stdc++.h>

using namespace std;

using Office = vector<vector<int>>;

/*
0: 빈칸
6: 벽
1~5: cctv(상하좌우), 최대 개수 8개
  1 : 단 방향, 상하좌우 (1000, 0100, 0010, 0001)
  2 : 두 방향, 반대 ㅡ ㅣ (1100, 0011)
  3 : 두 방향, 직각 (1010, 1001, 0110, 0101)
  4 : 세 방향, (1110, 1101, 1011, 0111)
  5 : 네 방향  (1111)

output : 사각지대의 최소 크기(0의 개수)
*/

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
  office_copy = office;

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      cin >> office[i][j];
      if((1 <= office[i][j]) && (office[i][j] <= 5))
        cctv_pos.push_back({i, j});
    }
  }
}

int count_zero(){
  int ret;
  for(const auto& row: office_copy){
    for(const auto& elem: row){
      if(elem == 0) ++ret;
    }
  }
  return ret;
}

int min_zero = 987654321;

int solve(int n){
  if(n == cctv_pos.size()){
    int ret = count_zero();
    min_zero = min(ret, min_zero);
  }
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  init();
}
```

## 회고(지나치게 간단한 문제는 생략 가능)


### 간단한 풀이와 접근 방식


### 주의할 지점
