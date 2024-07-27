# 6064-카잉 달력

```cpp
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}
int lcm(int a, int b){
    return a / gcd(a, b) *b;
}

int cal(int m, int n, int x, int y){
    if(x==m) x=0; // 원래는 m,n이지만 k번째를 구하기 위해 
    if(y==n) y=0; // x,y를 나머지처럼 0으로 바꾼다
    int l = lcm(m,n);
    //k가 x부터 시작해서 lcm까지
    //m으로 먼저 나누고 n으로 나눈다
    //m으로 나눈 나머지가 같은(=x) 수들의 목록
    for(int k = x; k<=l; k+=m){ 
        if(k==0) continue; //x랑 m이 같아서 0라면 m(=x)부터 시작
        if(k%n == y) return k; 
    }
    return -1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    while(n--){
        int m,n,x,y;
        cin >> m >> n >> x >> y;
        cout << cal(m, n, x, y) << '\n';
    }
}
```

## 풀이

만약 m=2,n=3으로 가정하고, 규칙을 고려해서 차례로 나열하면 다음과 같다

| 1 | 1 1 |
| --- | --- |
| 2 | 2 2 |
| 3 | 1 3 |
| 4 | 2 1 |
| 5 | 1 2 |
| 6 | 2 3 = <M:N> (달력의 마지막 해) |
| 1 | 1 1 |
| 2 | 2 2 … |

패턴이 6개씩 반복된다

<M:N>는 LCM(M,N)번째 해임을 알 수 있다 (위의 예시로 든다면 6)

∵ <M:N>이 되려면 그 해가 M으로도 나눠져야 하고 N으로도 나눠져야 한다 (x,y가 동시에 1이 되는 순간)

⇒ A × B = GCD(A,B) × LCM(A, B) 공식을 사용한다

따라서 1번째 해부터 LCM(M,N)번째 해까지에 대해서 N으로 나눈 나머지가 x이고 M으로 나눈 나머지가 y인지를 확인

## 시간초과

1. 문제에서 입출력 양이 많아져서 시간초과에 걸림

따라서 다음을 추가하여 시간초과를 예방

```cpp
ios::sync_with_stdio(false);
cin.tie(0);
```

2. 다시 시간초과 걸려서 

```cpp
for(int k = 1; k<= lcm(m,n); k++)
```

위 코드를 다음으로 변경

```cpp
int l = lcm(m,n);
for(int k = 1; k<=l; k++)
```

∵ for문 마다 lcm를 계산하는 것을 방지

3. 시간초과가 걸려서 이번에는 x부터 보고 그 후보들 중에 y를 살펴보기로 했다

```cpp
for(int k = 1; k<=l; k++){ //k번째 해
        if(k % m  == x && k % n == y){
            return k;
}
```

따라서 위 코드를 다음으로 바꾸었다

```cpp
for(int k = x; k<=l; k+=m){ 
        if(k==0) continue; //x랑 m이 같아서 0라면 m(=x)부터 시작
        if(k%n == y) return k; 
}
```