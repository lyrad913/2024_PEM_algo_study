# [9251-LCS](https://www.acmicpc.net/problem/9251)

## 풀이

```cpp
#include <bits/stdc++.h>

/*
ACAYKP -> ACA_K_
CAPCAK -> _A_CAK

최대 1000자. 0.1초
약 10^7 --> n^2 풀이도 괜찮겠네?
*/

using namespace std;

string s1, s2;
vector<vector<int>> cache;

// lsc : s1[it1:end], s2[it2:end]가 주어졌을때, lcs의 길이
int lcs(string::iterator it1, string::iterator it2) {
  // O(nm)
  // base case
  if (it1 == s1.end() || it2 == s2.end()) return 0;

  int& ret = cache[it1 - s1.begin()][it2 - s2.begin()];
  if (ret != -1) return ret;

  if (*it1 == *it2) {
    ret = 1 + lcs(it1 + 1, it2 + 1);
  } else {
    ret = max(lcs(it1 + 1, it2), lcs(it1, it2 + 1));
  }

  return ret;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> s1 >> s2;

  cache = vector<vector<int>>(s1.size(), vector<int>(s2.size(), -1));

  cout << lcs(s1.begin(), s2.begin());

  return 0;
}
```

(복잡도 생략 가능)  
시간 복잡도 : $O(mn)$  
공간 복잡도 : $O()$   

m : 문자열1의 길이
n : 문자열2의 길이,
동적 계획법을 적용했으니 저것보다는 한참 빠를듯

## 회고(지나치게 간단한 문제는 생략 가능)

### 간단한 풀이와 접근 방식

막막해서 완전 탐색을 해봤는데 시간초과가 걸린다? 고민없이 동적계획법

### 왜 그러한 풀이를 했는지?



### (틀렸다면) 오답 원인

처음에 양쪽 이터레이터를 하나씩 증가시킬 때 외에는 1을 더하면 안되나, 더해서 AAA/AAA(3)의 결과를 5로 계산했었다. 
그리고 항상 base case는 가장 간단하게.

### (참고했다면) 참고한 코드

- []()
#### 왜 저 풀이를 떠올리지 못했을까?

