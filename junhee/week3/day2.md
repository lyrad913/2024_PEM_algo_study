# [9663-N Queen](https://www.acmicpc.net/problem/9663)

## 풀이

```cpp
#include <bits/stdc++.h>

using namespace std;

int ret = 0;
int n; 
vector<int> queens; // queens[col] = row;

bool is_layable(int here){
  for(int i = 0; i < here; ++i){
    if(queens[here] == queens[i]||
      (((queens[here] - queens[i]) == (here - i))
        ||(queens[here] - queens[i]) == (i-here)))
      return false;
  }
  return true;
}

void solve(int here){
  if(here == n){ // base case
    ++ret;
  } else {
    for(int here_x = 0; here_x < n; ++here_x){
      queens[here] = here_x;
      if(is_layable(here))
        solve(here + 1);
    }
  }
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  queens = vector<int>(n);
  solve(0);
  cout << ret;
}
```

## 회고(지나치게 간단한 문제는 생략 가능)


### 간단한 풀이와 접근 방식


### 주의할 지점
