# [11003-최솟값찾기](https://www.acmicpc.net/problem/11003)

**~~시간 초과~~**

20% 통과에서 70% 통과로 개선

## 풀이

```cpp
#include <bits/stdc++.h>

using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, l;
  cin >> n >> l;
  
  vector<int> seq_a;
  int min_idx = -1;

  for(int i = 0; i < n; ++i){
    int a_i; cin >> a_i;
    seq_a.push_back(a_i);
    int start = max(0, i - l + 1);
    if(min_idx < start){
      min_idx = min_element(seq_a.begin() + start, seq_a.begin()+i+1) - seq_a.begin();
    } else {
      if (a_i <= seq_a[min_idx]){
        min_idx = i;
      }
    }
    cout << seq_a[min_idx] << " ";
  } 
}
```

(복잡도 생략 가능)  
시간 복잡도 : O(nl)  
n: 수열의 길이
l: 구간의 길이

## 회고(지나치게 간단한 문제는 생략 가능)

### 간단한 풀이와 접근 방식

최악의 경우에는 O(nl)
최소 인덱스를 저장해두고, 인덱스가 벗어나거나, 최솟값을 넘어가면 최소 인덱스를 갱신한다.

### 왜 그러한 풀이를 했는지? 

지금 내 수준에서 실전에서 떠올릴 수 있는 가장 나은 풀이.

### (틀렸다면) 오답 원인

시간 초과.

### (참고했다면) 참고한 코드

- [https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x07/solutions/11003.cpp]

deque를 사용한 풀이. 새로 추가된 수가 가장 끝에 위치하면서 가장 큰 수가 만든다. 그러기 위해서는 새로 입력되는 수보다 더 큰 수는 제거해야함. 

--> 떠오른 풀이 : 만약 최대 인덱스랑 최소 인덱스를 저장하는 변수 두 개를 둔다면 통과할 수 있을까?


#### 왜 저 풀이를 떠올리지 못했을까?

deque에 익숙하지 않음.

> 새로 추가된 수가 가장 끝에 위치하면서 가장 큰 수가 만든다. 그러기 위해서는 새로 입력되는 수보다 더 큰 수는 제거해야함. 

위와 같은 발상을 해본 적이 없다. 떠올리려면 많이 복습해야할 듯.