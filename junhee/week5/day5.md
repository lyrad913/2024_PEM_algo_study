# [1644-소수의 연속합](https://www.acmicpc.net/problem/1644)

## 풀이

```cpp
#include <bits/stdc++.h>

using namespace std;

bool is_prime(int n) {  // O(sqrt(n))
  if (n == 1) return false;
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) return false;
  }
  return true;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> seq;
  seq.reserve(n);

  // O(n*sqrt(n))
  for (int i = 1; i <= n; ++i) {
    if (is_prime(i)) {
      seq.push_back(i);
    }
  }

  int sum = seq.empty() ? 0 : seq[0];
  int ret = 0;
  // O(n)
  for (auto it = seq.begin(), it2 = seq.begin(); it != seq.end(); ++it) {
    while (it2 != seq.end() && sum < n) {
      ++it2;
      if (it2 != seq.end()) sum += *it2;
    }
    if (it2 == seq.end()) continue;
    if (sum == n) ++ret;
    sum -= *it;
  }

  cout << ret;

  return 0;
}
```

(복잡도 생략 가능)  
시간 복잡도 : $O(n\sqrt n)$  
공간 복잡도 : $O()$   



## 회고(지나치게 간단한 문제는 생략 가능)

### 간단한 풀이와 접근 방식

투 포인터

### 왜 그러한 풀이를 했는지?

연속인데 구간이고, 시간복잡도를 초과할 것 같다?

### (틀렸다면) 오답 원인

`while (it2 != seq.end() && sum < n) {` 이 줄에서 어이 없게 `&&`을 `,`로 사용함. 

### (참고했다면) 참고한 코드

- 소수 판별 알고리즘을 참고함. 익숙해질 것(시작은 2)

#### 왜 저 풀이를 떠올리지 못했을까?

# [22862-가장 긴 짝수 연속한 부분 수열(large)](https://www.acmicpc.net/problem/22862)

## 풀이

```cpp
#include <bits/stdc++.h>

using namespace std;

bool is_odd(int n) {
  if (n % 2 == 0) return false;
  return true;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<int> seq(n);
  for (int i = 0; i < n; ++i) {
    cin >> seq[i];
  }

  int n_odd = is_odd(seq[0]) ? 1 : 0;
  int max_length = is_odd(seq[0]) ? 0 : 1;

  for (auto it = seq.begin(), it2 = seq.begin(); it != seq.end(); ++it) {
    while (it2 != seq.end() && n_odd <= k) {
      ++it2;
      if (it2 != seq.end()) {
        if (is_odd(*it2)) ++n_odd;
        // cout << "n_odd : " << n_odd << is_odd(*it2) << '\n';
        // cout << *it << ", " << *it2 << '\n';
        int tmp_length = it2 - it + 1 - n_odd;
        // cout << tmp_length << '\n';
        max_length = max(max_length, tmp_length);
      }
    }
    if (it2 == seq.end()) continue;
    if (is_odd(*it)) --n_odd;
  }

  cout << max_length;

  return 0;
}
```

(복잡도 생략 가능)  
시간 복잡도 : $O(n)$  
공간 복잡도 : $O()$   



## 회고(지나치게 간단한 문제는 생략 가능)

### 간단한 풀이와 접근 방식

투 포인터

### 왜 그러한 풀이를 했는지?

처음에는 굉장히 막막했는데, 핵심 아이디어는 최대 k개를 뺄 수 있다는 건 특정 구간에서의 홀수 개수가 최대 k개까지 있을 수 있다는 말과 같다라는 점을 빨리 깨달은 덕에 풀 수 있었다.

### (틀렸다면) 오답 원인

항상 edge case를 조심하자. `max_length`변수의 초기화가 문제였는데, 으래 최대 문제에서 내가 하듯 -1로 초기화를 했다가 길이가 1일 때 된통 당했다. 최대 문제는 초기화할 때, 가능한 최솟값으로 설정하는 것이 중요하겠다.

### (참고했다면) 참고한 코드

#### 왜 저 풀이를 떠올리지 못했을까?

