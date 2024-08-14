# [1786-찾기](https://www.acmicpc.net/problem/1786)

## 풀이

```cpp
#include <bits/stdc++.h>

using namespace std;

vector<int> getPartialMatch(const string& N) {
  int m = N.size();
  vector<int> pi(m, 0);

  for (int begin = 1, matched = 0; begin + matched < m;) {
    if (N[begin + matched] == N[matched]) {
      ++matched;
      pi[begin + matched - 1] = matched;
    } else {
      if (matched == 0)
        ++begin;
      else {
        begin += matched - pi[matched - 1];
        matched = pi[matched - 1];
      }
    }
  }
  return pi;
}

vector<int> kmpSearch(const string& H, const string& N) {
  int n = H.size(), m = N.size();
  vector<int> ret;
  vector<int> pi = getPartialMatch(N);

  for (int begin = 0, matched = 0; begin <= n - m;) {
    if (matched < m && H[begin + matched] == N[matched]) {
      ++matched;
      if (matched == m) {
        ret.push_back(begin);
      }
    } else {
      if (matched == 0)
        ++begin;
      else {
        begin += matched - pi[matched - 1];
        matched = pi[matched - 1];
      }
    }
  }
  return ret;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string T, P;
  getline(cin, T);
  getline(cin, P);

  auto ret = kmpSearch(T, P);
  cout << ret.size() << '\n';
  for (auto elem : ret) {
    cout << elem + 1 << "\n";
  }

  return 0;
}
```

(복잡도 생략 가능)  
시간 복잡도 : $O(|T| + |P|)$  
공간 복잡도 : $O()$   



## 회고(지나치게 간단한 문제는 생략 가능)

### 간단한 풀이와 접근 방식

kmp 알고리즘 연습

### 왜 그러한 풀이를 했는지?

너무 어려운데요.. 이해가 안돼요...

### (틀렸다면) 오답 원인



### (참고했다면) 참고한 코드

  
#### 왜 저 풀이를 떠올리지 못했을까?

