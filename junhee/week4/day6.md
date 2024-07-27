# [14002-가장 긴 증가하는 부분 수열](https://www.acmicpc.net/problem/14002)

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
  for (int i = 1; i <= cache.size(); ++i) {
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



### 왜 그러한 풀이를 했는지?



### (틀렸다면) 오답 원인

게시판에 존재하는 반례를 다 통과하는데도, 1%에서 틀림. 코드가 문제가 되는 부분을 못찾겟음. 내일 마저 생각해보기

### (참고했다면) 참고한 코드


#### 왜 저 풀이를 떠올리지 못했을까?

