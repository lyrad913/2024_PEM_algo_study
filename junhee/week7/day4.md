# [15650-N과 M(2)](https://www.acmicpc.net/problem/15650)

## 풀이

```cpp
#include <bits/stdc++.h>

using namespace std;

vector<int> ret;

// start부터 end까지의 자연수 중 중복없이 오름차순으로 m개를 뽑은 수열
void solve(int start, int end, int m) {
  // base case
  if (m == 0) {
    for (int e : ret) {
      cout << e << " ";
    }
    cout << '\n';
    return;
  }
  for (int i = start + 1; i <= end - m + 1; ++i) {
    ret.push_back(i);
    solve(i, end, m - 1);
    ret.pop_back();
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  ret.reserve(m);

  solve(0, n, m);

  return 0;
}
```

(복잡도 생략 가능)  
시간 복잡도 : $O(\binom{n}{m}n)$  
공간 복잡도 : $O()$   

존재할 수 있는 부분 문제의 개수는 n개의 원소 중에 m개($\binom{n}{m}$)를 뽑는 것과 동일함. 각 부분 문제에서 반복문 수행횟수는 최대 $n$

## 회고(지나치게 간단한 문제는 생략 가능)

### 간단한 풀이와 접근 방식



### 왜 그러한 풀이를 했는지?


### (틀렸다면) 오답 원인

이런 문제는 출력이 제일 어려워... 익숙해지자

### (참고했다면) 참고한 코드

#### 왜 저 풀이를 떠올리지 못했을까?

