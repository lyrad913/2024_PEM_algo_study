# [14425-문자열집합](https://www.acmicpc.net/problem/14425)

## 풀이

```cpp
#include <bits/stdc++.h>

using namespace std;

const int ROOT = 1;
int unused = 2;
// 최대 등장 가능 글자 수
const int MAX = 10000 * 500 + 5;
bool chk[MAX];
int nxt[MAX][26];

int c_to_i(char ch) { return ch - 'a'; }

void init() {
  for (int i = 0; i < MAX; ++i) {
    fill(nxt[i], nxt[i] + 26, -1);
  }
}

void insert(const string& s) {
  int cur = ROOT;
  for (auto ch : s) {
    int there = c_to_i(ch);
    if (nxt[cur][there] == -1) nxt[cur][there] = unused++;
    cur = nxt[cur][there];
  }
  chk[cur] = true;
}

bool find(const string& s) {
  int cur = ROOT;
  for (auto ch : s) {
    int there = c_to_i(ch);
    if (nxt[cur][there] == -1) return false;
    cur = nxt[cur][there];
  }
  return chk[cur];
}

void erase(const string& s) {
  int cur = ROOT;
  for (auto ch : s) {
    int there = c_to_i(ch);
    if (nxt[cur][there] == -1) return;
    cur = nxt[cur][there];
  }
  chk[cur] = false;
}

int n, m;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  init();

  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    insert(s);
  }

  int ans = 0;
  for (int i = 0; i < m; ++i) {
    string s;
    cin >> s;
    ans += find(s);
  }

  cout << ans;

  return 0;
}
```

(복잡도 생략 가능)  
시간 복잡도 : $O((n+m)\|S\|)$  
공간 복잡도 : $O()$   



## 회고(지나치게 간단한 문제는 생략 가능)

### 간단한 풀이와 접근 방식



### 왜 그러한 풀이를 했는지?



### (틀렸다면) 오답 원인



### (참고했다면) 참고한 코드

- []()
#### 왜 저 풀이를 떠올리지 못했을까?

