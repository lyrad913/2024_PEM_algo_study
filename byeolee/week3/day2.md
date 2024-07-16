# 1629-곱셈

```cpp
#include <iostream>
using namespace std;

using ll = long long;
ll power(ll a, ll b, ll c){
    if(b==0) return 1;
    if(b==1) return a % c;
    ll d = power(a, b/2, c); // a^(b/2)
    ll e = d*d % c;
    if(b%2==0) return e; //b가 짝수일때
    return e*a % c; //b가 홀수일때
}

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    cout << power(a,b,c);
}
```

## 풀이

그냥 a를 b번 곱해준 뒤 c로 나누면 overflow가 발생한다

큰 수를 처리하기 위해 **divide & conquer**를 사용하여 수를 쪼개어 값을 계산할 수 있게 한다

1승을 계산할 수 있고 k승을 계산했으면 2k승과 2k+1승도 계산할 수 있다

b가 짝수: a^b = a^(b/2) * a^(b/2)

b가 홀수: a^b = a^(b/2) * a^(b/2+1) = a^(b/2)*a^(b/2)*a

강의에서 `long long` 을 타입 에일리어스 하길래 따라했다

`ll power` 함수는 b가 0인지, 1인지, 짝수인지, 홀수인지에 따라 경우가 나누어지게 된다

## 복잡도

### 시간복잡도

재귀 호출 부분 외에 다른 부분은 O(1)이며 따라서 재귀 호출 부분만 고려하면 된다

재귀 호출의 깊이는 b를 절반으로 줄이는 과정에서 결정된다

b의 초기값이 2^k일 때, 최종적으로 b가 0 또는 1이 될 때까지 k번의 재귀 호출을 한다 ⇒ k = log2(b) 

∴ O(logN)

### 공간복잡도

재귀 함수가 자기 자신을 부를 때 스택 영역에 계속 누적이 된다

각 재귀 호출은 스택에 새로운 프레임을 추가한다

log2(b)번 재귀 호출을 한다

⇒ O(logN)