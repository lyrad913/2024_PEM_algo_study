# [15654`-N과 M 5](https://www.acmicpc.net/problem/15654`)

## 풀이

```cpp
#include <bits/stdc++.h>

using namespace std;

vector<int> ret;

void solve(const vector<int>& seq, int m) {
  if (m == 0) {
    for (auto e : ret) {
      cout << e << " ";
    }
    cout << '\n';
    return;
  }
  for (auto it = seq.begin(); it != seq.end(); ++it) {
    ret.push_back(*it);
    vector<int> to_pass = vector<int>(seq.begin(), it);
    to_pass.insert(to_pass.end(), it + 1, seq.end());
    solve(to_pass, m - 1);
    ret.pop_back();
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int> seq(n);
  for (int i = 0; i < n; ++i) {
    cin >> seq[i];
  }

  sort(seq.begin(), seq.end());

  solve(seq, m);

  return 0;
}
```

(복잡도 생략 가능)  
시간 복잡도 : $O(NM)$  
공간 복잡도 : $O()$   



## 회고(지나치게 간단한 문제는 생략 가능)

### 간단한 풀이와 접근 방식



### 왜 그러한 풀이를 했는지?



### (틀렸다면) 오답 원인

stl insert()함수에 익숙해지자!

### (참고했다면) 참고한 코드

#### 왜 저 풀이를 떠올리지 못했을까?

