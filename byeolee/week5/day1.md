# 11050-이항 계수1

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    int s=1;
    for(int i=1; i<=n; i++) s *= i;
    for(int i=1; i<=n-k; i++) s /= i;
    for(int i=1; i<=k; i++) s /= i;
    cout << s;
}
```

## 풀이

팩토리얼을 구현하여 이항계수 공식을 나타내었다

## 복잡도

### 시간복잡도

O(N) + O(N-K) + O(K) = O(N)

### 공간복잡도

s, i, n, k 변수 → O(1)