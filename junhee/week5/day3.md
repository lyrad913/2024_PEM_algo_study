# [2230-수 고르기](https://www.acmicpc.net/problem/2230)

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
  for (int i = 0; i < n; ++i) {
    int idx = lower_bound(seq.begin() + i, seq.end(), m + seq[i]) - seq.begin();
    if (idx != n) {
      min_diff = min(min_diff, seq[idx] - seq[i]);
    }
  }
  cout << min_diff;

  return 0;
}
```

(복잡도 생략 가능)  
시간 복잡도 : $O()$  
공간 복잡도 : $O()$   



## 회고(지나치게 간단한 문제는 생략 가능)

### 간단한 풀이와 접근 방식

투 포인터 🔄 이분탐색 풀이 연습

### 왜 그러한 풀이를 했는지?



### (틀렸다면) 오답 원인



### (참고했다면) 참고한 코드


#### 왜 저 풀이를 떠올리지 못했을까?


# [1806-부분합](https://www.acmicpc.net/problem/1806)

## 풀이

```cpp
#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, s;
  cin >> n >> s;
  vector<int> seq(n);

  for (int i = 0; i < seq.size(); ++i) {
    cin >> seq[i];
  }

  int min_length = 100001;
  int partial_sum = seq[0];
  for (int i = 0, j = 0; i < seq.size(); ++i) {
    while (j < seq.size() && partial_sum < s) {
      ++j;
      if (j != seq.size()) partial_sum += seq[j];
    }
    if (j == seq.size()) break;
    min_length = min(min_length, j - i + 1);
    partial_sum -= seq[i];
  }

  min_length = min_length == 100001 ? 0 : min_length;

  cout << min_length;

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

$O(n^2)$인 이중for문으로는 시간제한에 걸려서 떨궈야하는데, 이전의 정보를 저장하면 좋을 것 같기 때문

### (틀렸다면) 오답 원인

while문의 탈출 조건을 for문의 탈출조건에 넣어버리면, for문 안의 내용이 어쨌든 실행되면서 의도와 다른 결과가 나올 수 있다.

### (참고했다면) 참고한 코드

#### 왜 저 풀이를 떠올리지 못했을까?

# [7785-회사에 있는 사람](https://www.acmicpc.net/problem/7785)

## 풀이

```cpp
#include <bits/stdc++.h>

using namespace std;

// TODO: 이분탐색, 투 포인터 풀이 해보기
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  unordered_set<string> s;

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string name, log;
    cin >> name >> log;
    if (log == "enter") {
      s.insert(name);
    } else {
      s.erase(name);
    }
  }

  vector<string> ret(s.begin(), s.end());
  sort(ret.begin(), ret.end(), greater<string>());

  for (const auto& elem : ret) {
    cout << elem << '\n';
  }

  return 0;
}
```

(복잡도 생략 가능)  
시간 복잡도 : $O(nlogn)$  
공간 복잡도 : $O()$   

해시는 입력, 삭제, 탐색 O(1)(최악의 경우는 O(n)), 따라서, 밑의 정렬이 지배함

## 회고(지나치게 간단한 문제는 생략 가능)

### 간단한 풀이와 접근 방식



### 왜 그러한 풀이를 했는지?



### (틀렸다면) 오답 원인



### (참고했다면) 참고한 코드


#### 왜 저 풀이를 떠올리지 못했을까?

