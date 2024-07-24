# 1978-소수 찾기

```cpp
#include <iostream>
using namespace std;

bool isprime(int x){
    if(x==1) return 0; // 1을 제외
    for(int i=2; i*i<=x; i++){ // 2부터 √x 까지의 수로 나누어지면 제외
        if(x%i == 0) return 0;
    }
    return 1;
}
int main(){
    int n; int cnt=0;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        cnt += isprime(x);
    }
    cout << cnt;
}
```

## 풀이

소수: 1과 자기 자신으로만 나누어지는 수, 약수가 2개인 수

합성수: 1과 자기 자신을 제외한 다른 약수를 가지고 있는 수

합성수 x에서 1을 제외한 **가장 작은 약수는 √x 이하**이다

→ 2부터 √x 까지의 수로 나누어지지 않으면 소수이다

## 오답

for문에서 조건이 2부터 √x 까지의 수이므로 √x를 포함해야 하는데 포함하지 않았다

`i*i < x` 조건을 `i*i <= x` 로 바꾸어야 한다

## 복잡도

### 시간복잡도

`isprime` 함수: 입력 x에 대해  √x 번의 연산을 한다 → O(√x)

메인 함수: while문에서 n 개의 입력에 대해 각각 isprime 함수를 호출한다

∴ O(n√x)

### 공간복잡도

n개의 수를 저장하지 않고 하나씩 처리한다

∴ O(1)