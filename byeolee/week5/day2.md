# 11051-이항 계수2

```cpp
#include <bits/stdc++.h>
using namespace std;

int c[1001][1001];
int mod = 10007;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=1; i <=1000; i++){
        c[i][0] = c[i][i] = 1;
        for(int j=1; j<i; j++){ //c[i][0],c[i][i]제외 나머지
            c[i][j] = (c[i-1][j] + c[i-1][j-1])%mod; 
            //매번 나누어주지 않으면 자료형의 크기를 초과하게 된다
        }
    }
    int n, m;
    cin >> n >> m;
    cout << c[n][m];
}
```

## 풀이

nCk = (n-1)C(k-1) + (n-1)Ck 공식 이용해서 1C0부터 1000C1000까지 10007로 나누었을 때의 나머지를 배열에 저장한다