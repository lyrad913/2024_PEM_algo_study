# 10773-제로

```cpp
#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<int> s;
    int n;
    int k; // 숫자 개수
    cin >> k;
    for(int i=0; i<k; i++){
        cin >> n;
        if(n != 0){
            s.push(n);
        }
        else if(n == 0){
            s.pop();
        }
    }
    int sum = 0;
    while(!s.empty()){ 
        sum += s.top();
        s.pop();
    }
    cout << sum;
}
```

### 오답

출력이 이상하게 나와서 살펴봤더니 `int sum` 을 초기화 하지 않고 합을 계산하여 쓰레기값이 나왔다

### 풀이

정수가 "0" 일 경우에는 가장 최근에 쓴 수를 지운다 → 스택을 활용

k개의 줄에 정수가 1개씩 주어진다 → for문을 활용하여 k번 반복

받은 수가 0인 경우와 아닌 경우로 나눈다 → if문 사용

스택이 바닥날 때까지 요소들을 합한다 → while문 사용

### 복잡도

입력을 처리하는 데에 루프는 k번 반복된다, `push` 와 `pop` 연산은 각각 O(1) 

→ O(n)

원소들의 합을 계산할 때 스택에 최대 k개의 요소가 있을 수 있기 때문에 루프는 최대 k번 반복된다, 각 반복에서 `top`과 `pop` 연산은 O(1)를 가진다 

→ O(n)

시간복잡도: 두 루프의 시간 복잡도 합치면 O(n)

스택 `s` 는 최대 k개의 요소를 저장한다, `n`, `k`, `sum` 각각 O(1) 공간을 차지

→ 공간복잡도: O(n)