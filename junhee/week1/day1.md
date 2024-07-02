# [10871-X보다 작은 수](https://www.acmicpc.net/problem/10871)

n = N(A)인 수열A가 제공, A의 원소 중 x보다 작은 원소를 순서대로 출력하시오

## 풀이

```cpp
#include <bits/stdc++.h>

using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n = 1, x = 1;
  cin >> n >> x;
  for(int i = 0; i < n; ++i){
    int tmp;
    cin >> tmp;
    if(tmp < x) cout << tmp << " ";
  }
}
```

(복잡도 생략 가능)  
시간 복잡도 : O(n)  
공간 복잡도 : O(1)

n : 수열 a의 길이

## 회고(지나치게 간단한 문제는 생략 가능)

### 간단한 풀이와 접근 방식

하나씩 입력받으면서 X와 비교하며 작으면 출력(이하가 아닌 것에 주의)

### 왜 그러한 풀이를 했는지? 

오름차순/내림차순 등이 아니기 때문에 배열로 굳이 저장하지 않아도 괜찮다.

### 오답 원인

놀랍게도 한 번 틀림. 출력 형태 잘 맞추기...

### ~~(참고했다면) 참고한 코드~~



#### ~~왜 저 풀이를 떠올리지 못했을까?~~

다음에 저런 풀이를 떠올리려면?
