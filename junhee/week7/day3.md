# [1254-팰린드롬 만들기](https://www.acmicpc.net/problem/1254)

## 풀이

```cpp
#include <bits/stdc++.h>

using namespace std;

vector<int> getPartialMatch(const string& s) {
  vector<int> pi(s.size(), 0);
  for (int begin = 1, matched = 0; begin + matched <= s.size();) {
    if (s[begin + matched] == s[matched]) {
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

int maxOverlap(const string& a, const string& b) {
  int n = a.size(), m = b.size();
  vector<int> pi = getPartialMatch(b);
  for (int begin = 0, matched = 0; begin < n;) {
    if (matched < m && a[begin + matched] == b[matched]) {
      ++matched;
      if (begin + matched == n) return matched;
    } else {
      if (matched == 0)
        ++begin;
      else {
        begin += matched - pi[matched - 1];
        matched = pi[matched - 1];
      }
    }
  }
  return 0;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  string rs(s);
  reverse(rs.begin(), rs.end());
  int max_overlap = maxOverlap(s, rs);

  cout << 2 * s.size() - max_overlap;

  return 0;
}
```

(복잡도 생략 가능)  
시간 복잡도 : $O(|S|)$  
공간 복잡도 : $O()$   



## 회고(지나치게 간단한 문제는 생략 가능)

### 간단한 풀이와 접근 방식

접두사와 접미사가 최대한 겹치게 만들어야하니까 kmp와 유사한 접근을 시도

### 왜 그러한 풀이를 했는지?



### (틀렸다면) 오답 원인



### (참고했다면) 참고한 코드

#### 왜 저 풀이를 떠올리지 못했을까?

