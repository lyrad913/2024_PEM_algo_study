# [11003-최솟값찾기](https://www.acmicpc.net/problem/11003)

**~~시간 초과~~**

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

  for(int i = 0; i < n; ++i){
    int a_i; cin >> a_i;
    seq_a.push_back(a_i);
    int start = max(0, i - l + 1);
    int d_min = *min_element(seq_a.begin() + start, seq_a.begin()+i+1); // O(l)
    cout << d_min << " ";
  } 
}
```

(복잡도 생략 가능)  
시간 복잡도 : O(nl)  
n: 수열의 길이
l: 구간의 길이

## 회고(지나치게 간단한 문제는 생략 가능)

### 간단한 풀이와 접근 방식

벡터의 반복자를 활용해서 구간 마다 최솟값을 찾아보자.

### 왜 그러한 풀이를 했는지? 

가장 단순하게 떠올릴 수 있는 풀이!

### (틀렸다면) 오답 원인

시간 초과. 시간복잡도를 낮춰야함. 메모리를 추가로 둬야할듯. 내일 다시 시도해보고 답지 봐보기.

### (참고했다면) 참고한 코드

- [코드](링크)
- ...


#### 왜 저 풀이를 떠올리지 못했을까?