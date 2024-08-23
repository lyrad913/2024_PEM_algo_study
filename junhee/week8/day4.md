# [1629-곱셈](https://www.acmicpc.net/problem/1629)

## 풀이

```cpp
#include <bits/stdc++.h>

using namespace std;

int solve(int a, int b, int c) {
  if (b == 0) return 1;
  if (b == 1) return a % c;

  long long int k = solve(a, b / 2, c);
  if (b % 2 == 0)
    return ((k % c) * (k % c)) % c;
  else
    return ((((k % c) * (k % c)) % c) * (a % c)) % c;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b, c;
  cin >> a >> b >> c;

  cout << solve(a, b, c);

  return 0;
}
```

(복잡도 생략 가능)  
시간 복잡도 : $O(\log{b})$  
공간 복잡도 : $O()$   



## 회고(지나치게 간단한 문제는 생략 가능)

### 간단한 풀이와 접근 방식

- $a^{m+n} = a^m*a^n$
- $(a*b)\%c = (a\%c * b\%c)\%c$
- $\therefore a^{m+n} \% c = \cdots$

### 왜 그러한 풀이를 했는지?



### (틀렸다면) 오답 원인

나머지 간의 곱에서 오버플로 발생 가능

### (참고했다면) 참고한 코드


#### 왜 저 풀이를 떠올리지 못했을까?

