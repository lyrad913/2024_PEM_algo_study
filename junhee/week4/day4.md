# [2240-자두나무](https://www.acmicpc.net/problem/2240)

## 풀이

```cpp
#include <bits/stdc++.h>

using namespace std;

int T, W;
vector<int> tree_info;
vector<vector<int>> cache;

// solve() : i초경과 j번 움직였을 때 먹은 최대 자두의 개수.
int solve(int second, int movement){
  if(second == 0){ 
    return 0;
  }

  int& ret = cache[second][movement];
  if(ret != -1) return ret;
  int cur_zado = movement % 2;

  return ret = max(solve(second - 1, movement), solve(second - 1, movement - 1))
              + (cur_zado == (tree_info[second]-1));
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> T >> W;
  cache = vector<vector<int>>(T+1, vector<int>(W+1, -1));
  tree_info = vector<int>(T+1);
  for(int i = 1; i <= T; ++i)
    cin >> tree_info[i];

  // 첫번째 열매가 떨어지기 전에 이동할 수 있음.
  cout << max(solve(T, W), solve(T, W-1));

  return 0;
}
```

(복잡도 생략 가능)  
시간 복잡도 : $O()$  
공간 복잡도 : $O()$   

공간복잡도는 TW, 시간 복잡도는 중복도에 따라 다르겠다.

## 회고(지나치게 간단한 문제는 생략 가능)

### 간단한 풀이와 접근 방식

문제가 자두가 T초 지났을 때, 먹을 수 있는 자두의 개수를 구하는 것이니, 거기에 맞춰서 함수를 설계한다. 중복되는 부분은 메모이제이션을 적용한다.

### 왜 그러한 풀이를 했는지?

$2^30$가지의 경우의 수가 있는데, 이는 시간 안에 조금 버거울지두?

### (틀렸다면) 오답 원인

자두가 떨어지기 전에 자두가 움직일 수 있다는 사실을 간과하였다. `main`함수의 `cout`을 보자.

### (참고했다면) 참고한 코드


#### 왜 저 풀이를 떠올리지 못했을까?

