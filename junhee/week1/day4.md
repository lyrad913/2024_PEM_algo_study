# [10773-제로](https://www.acmicpc.net/problem/10773)

## 풀이

```cpp
#include <bits/stdc++.h>

using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int k; cin >> k;

  stack<int> s;

  for(int i = 0; i < k; ++i){
    int money; cin >> money;
    if(money == 0) s.pop(); // ensure
    else s.push(money);
  }

  int ret = 0;
  while(!s.empty()){
    ret += s.top();
    s.pop();
  }
  cout << ret;
}
```

(복잡도 생략 가능)  
시간 복잡도 : O(k)  

## 회고(지나치게 간단한 문제는 생략 가능)

간단한 스택 연습 문제. 

### 간단한 풀이와 접근 방식

### 왜 그러한 풀이를 했는지? 

가장 "최근"에 대한 조작이므로 스택 결정

### (틀렸다면) 오답 원인

### (참고했다면) 참고한 코드

- [코드](링크)
- ...

간략한 해설

#### 왜 저 풀이를 떠올리지 못했을까?

다음에 저런 풀이를 떠올리려면?

# [2164-카드2](https://www.acmicpc.net/problem/2164)

## 풀이

```cpp
#include <bits/stdc++.h>

using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n; // n > 1

  queue<int> q;
  for(int i = 1; i <= n; ++i)
    q.push(i);

  bool to_dump = true;
  while(q.size() > 1){
    if(to_dump) q.pop();
    else {
      q.push(q.front());
      q.pop();
    }
    to_dump = !to_dump;
  }

  cout << q.front();
}
```

(복잡도 생략 가능)  
시간 복잡도 : O(k)  

## 회고(지나치게 간단한 문제는 생략 가능)

간단한 큐 연습 문제. 

### 간단한 풀이와 접근 방식

### 왜 그러한 풀이를 했는지? 

위의 카드가 다시 밑으로 들어가는 등의 순환이 보이면 큐를 생각해본다.

### (틀렸다면) 오답 원인

### (참고했다면) 참고한 코드

- [코드](링크)
- ...

간략한 해설

#### 왜 저 풀이를 떠올리지 못했을까?

다음에 저런 풀이를 떠올리려면?