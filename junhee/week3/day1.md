# [2630-색종이 만들기](https://www.acmicpc.net/problem/2630)

## 풀이

```cpp
#include <bits/stdc++.h>

using namespace std;
using PAPER = vector<vector<int>>;

pair<int, int> operator +(const pair<int, int>& x, const pair<int, int>& y){
  return pair<int, int>(x.first + y.first, x.second + y.second);
}

bool isSame(const pair<int, int>& part1, const pair<int, int>& part2,
            const pair<int, int>& part3, const pair<int, int>& part4)
{
  return ((part1.first == 0 && part2.first == 0 && part3.first == 0 && part4.first == 0)
        || (part1.second == 0 && part2.second == 0 && part3.second == 0 && part4.second == 0));
}

// solve(n, y, x) : (y, x)에서 n by n 색종이를 잘랐을 때, 흰색 종이와 파란 종이의 개수 
pair<int, int> solve(int n, int y, int x, const PAPER& paper){
  if(n == 1) { // base condition
    if(paper[y][x] == 0) return make_pair(1, 0);
    else return make_pair(0, 1);
  }

  int next_n = n / 2;
  int there_y = y + next_n;
  int there_x = x + next_n;

  auto ret1 = solve(next_n, y, x, paper);
  auto ret2 = solve(next_n, there_y, x, paper);
  auto ret3 = solve(next_n, y, there_x, paper);
  auto ret4 = solve(next_n, there_y, there_x, paper);
  
  if(isSame(ret1, ret2, ret3, ret4)){
    if(paper[y][x] == 0) return make_pair(1, 0);
    else return make_pair(0, 1);
  } else {
    return ret1 + ret2 + ret3 + ret4;
  }
}

int main(void){

  int n; cin >> n;

  PAPER paper(n, vector<int>(n));

  for(auto& l: paper)
    for(auto& elem: l)
      cin >> elem;

  auto ret = solve(n, 0, 0, paper);

  cout << ret.first << '\n' << ret.second;

  return 0;
}
```

## 회고(지나치게 간단한 문제는 생략 가능)

간만에 재귀로 풀어본 문제!

### 간단한 풀이와 접근 방식

사실상 문제를 그대로 풀이로 옮겼다.

주어진 색종이를 4등분 해서 같은 색이면 하나, 다른 색이면 쪼갠다.

### 주의할 지점

for-each문은 기본적으로 값을 복사한다. reference를 활용해서 변수 그 자체를 가져오자.

재귀는 언제나 함수를 잘 정의하는데서 시작.