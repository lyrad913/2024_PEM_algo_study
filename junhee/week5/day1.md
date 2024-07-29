# [14002-가장 긴 증가하는 부분 수열 4](https://www.acmicpc.net/problem/14002)

## 풀이

```cpp
#include <bits/stdc++.h>

using namespace std;

vector<int> seq;
vector<pair<int, int>> cache;  // length, idx;

// solve(n): 0부터 n까지의 수열 중 n을 포함하는 가장 긴 증가하는 부분 수열의
// 길이와 본인 이전의 원소의 인덱스를 반환(길이, 직전인덱스)
pair<int, int> solve(int n) {
  pair<int, int>& ret = cache[n];
  if (n == 1) {  // base case
    ret = {1, -1};
    return ret;
  }

  if (ret.first != -1) return ret;
  ret.first = 1;
  for (int i = 1; i < n; ++i) {
    auto cand = solve(i);
    if (seq[n] > seq[i]) {
      ret = cand.first + 1 > ret.first ? make_pair(cand.first + 1, i) : ret;
    }
  }
  return ret;
}

void output() {
  int max_idx = 0;
  for (int i = 1; i < cache.size(); ++i) {
    max_idx = cache[max_idx].first < cache[i].first ? i : max_idx;
  }
  int idx = max_idx;
  stack<int> ret;
  while (idx != -1) {
    ret.push(idx);
    idx = cache[idx].second;
  }
  cout << cache[max_idx].first << "\n";
  while (!ret.empty()) {
    cout << seq[ret.top()] << " ";
    ret.pop();
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  seq = vector<int>(n + 1, 0);
  cache = vector<pair<int, int>>(n + 1, {-1, -1});
  for (int i = 1; i <= n; ++i) {
    cin >> seq[i];
  }

  solve(n);
  output();

  return 0;
}
```

(복잡도 생략 가능)  
시간 복잡도 : $O()$  
공간 복잡도 : $O()$   



## 회고(지나치게 간단한 문제는 생략 가능)

### 간단한 풀이와 접근 방식

`solve()`의 주석 확인

### 왜 그러한 풀이를 했는지?

문제를 풀려고 하면, 배열을 구하기보다는 길이를 구하는게 더 쉽다는 것을 알 수 있다.   
길이를 구하면서, 직전 원소의 정보를 기록해두면 나중에 가장 긴 부분 수열을 찾아서 출력할 수 있음.

### (틀렸다면) 오답 원인

`output()`의 첫번째 `for`문의 조건이 문제였다. 보통 동적 계획법을 다룰 때, 직관적으로 접근하기 위해 캐시의 크기를 n+1로 잡는다. 그래서 반복분을 돌거나 할 때 조건이 `<=n`이 되게 되는데, 문제는 벡터의 사이즈는 n+1이었던 것. 가독성을 위해 배열이 아닌 벡터를 쓰다가, 스스로 함정에 빠졌다.

### (참고했다면) 참고한 코드

#### 왜 저 풀이를 떠올리지 못했을까?