# [11003-최솟값찾기](https://www.acmicpc.net/problem/11003)

## 풀이

```cpp
#include <bits/stdc++.h>

using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, window; cin >> n >> window;

  deque<pair<int, int>> dq;
  for(int i = 0; i < n; ++i){
    int elem; cin >> elem;

    while(!dq.empty() && dq.back().second >= elem){
      dq.pop_back();
    } 

    dq.push_back({i, elem});

    if(dq.front().first <= i - window){
      dq.pop_front();
    }

    cout << dq.front().second << " " ;
  }

  return 0;
}
```

(복잡도 생략 가능)  
시간 복잡도 : $O()$  
공간 복잡도 : $O()$   



## 회고(지나치게 간단한 문제는 생략 가능)

### 간단한 풀이와 접근 방식

덱을 사용한 주어진 구간의 최솟값 찾기

### 왜 그러한 풀이를 했는지?

별 방법을 다 써봤는데, 결국은 시간 제한에 걸렸다.

### (틀렸다면) 오답 원인

푸는 법을 몰랐음

### (참고했다면) 참고한 코드

#### 왜 저 풀이를 떠올리지 못했을까?

앞으로는 주어진 구간의 최대, 최소가 보이면 덱을 떠올릴 것