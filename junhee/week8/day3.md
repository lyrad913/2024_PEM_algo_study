# [1149-RGB거리](https://www.acmicpc.net/problem/1149)

## 풀이

```cpp
#include <bits/stdc++.h>
enum color { red, green, blue, not_color };

color colors[3] = {color::red, color::green, color::blue};

using namespace std;
vector<vector<int>> cost;  // 0 for convinience
vector<vector<int>> cache;

// solve(here, cur_color) : here에 cur_color를 칠했을 때,
//                          가능한 모든 집 칠하기의 최솟값.
int solve(int here, color cur_color) {
  if (here == cost.size()) {
    return 0;
  }

  int& ret = cache[here][cur_color];
  if (ret != 1000001) return ret;
  // int ret = 1000001;
  for (int i = 0; i < 3; ++i) {
    if (colors[i] != cur_color)
      ret = min(ret, cost[here][cur_color] + solve(here + 1, colors[i]));
  }
  return ret;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  cost = vector<vector<int>>(n + 1, vector<int>(3, 0));
  cache = vector<vector<int>>(n + 1, vector<int>(4, 1000001));

  for (int i = 1; i < n + 1; ++i) {
    for (int j = 0; j < 3; ++j) {
      cin >> cost[i][j];
    }
  }

  cout << solve(0, color::not_color);

  return 0;
}
```

(복잡도 생략 가능)  
시간 복잡도 : $O(3^n)$  
공간 복잡도 : $O()$   

## 회고(지나치게 간단한 문제는 생략 가능)

### 간단한 풀이와 접근 방식

동적계획법 문제. 

### 왜 그러한 풀이를 했는지?

시간초과 + 정의한 부분 문제가 이전의 결정에 영향을 받지 않음.(즉, 입력이 주어지면 출력은 항상 동일함)

### (틀렸다면) 오답 원인

완전 탐색은 무난하게 맞았고, 동적 계획법을 적용할 때 계속 틀려서 '이거 왜 이래?'했었는데, 원인은 편의를 위해 뒀던 `0, not_color`이 두 값이 문제였다. 메모리가 낭낭하길래, 그냥 cache에 메모리를 더 줌

### (참고했다면) 참고한 코드

#### 왜 저 풀이를 떠올리지 못했을까?

