# [2230-수고르기](https://www.acmicpc.net/problem/2230)

## 풀이

```cpp
#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int> seq(n);
  for (auto& elem : seq) cin >> elem;

  sort(seq.begin(), seq.end());

  int min_diff = 2000000000;
  // for (int i = 0; i < n; ++i) {
  //   for (int j = i; j < n; ++j) {
  //     int tmp_diff = abs(seq[i] - seq[j]);
  //     min_diff = tmp_diff > m ? min(min_diff, tmp_diff) : min_diff;
  //   }
  // }
  for (int i = 0, j = 0; i < n; ++i) {
    while (j < n && seq[j] - seq[i] < m) ++j;
    if (j == n) break;
    min_diff = min(min_diff, seq[j] - seq[i]);
  }
  cout << min_diff;

  return 0;
}
```

(복잡도 생략 가능)  
시간 복잡도 : $O(n)$  
공간 복잡도 : $O()$   



## 회고(지나치게 간단한 문제는 생략 가능)

### 간단한 풀이와 접근 방식

투 포인터 접근 방법 감 익히기

### 왜 그러한 풀이를 했는지?



### (틀렸다면) 오답 원인



### (참고했다면) 참고한 코드


#### 왜 저 풀이를 떠올리지 못했을까?

