# [1918-후위 표기식](https://www.acmicpc.net/problem/1918)

## 풀이

```cpp
#include <bits/stdc++.h>

using namespace std;

/*
a+b*c -> (a + (b*c)) -> abc*+
operand   : a -> a  -> ab  -> abc...
operator  : ( -> (+ -> (+  -> (+(*)...
*/

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string me;
  cin >> me;

  stack<char> op;

  for (int i = 0; i < me.size(); ++i) {
    if (me[i] == '+' || me[i] == '-') {
      while (!op.empty() && op.top() != '(') {
        cout << op.top();
        op.pop();
      }
      op.push(me[i]);
    } else if (me[i] == '*' || me[i] == '/') {
      while (!op.empty() && (op.top() == '*' || op.top() == '/')) {
        cout << op.top();
        op.pop();
      }
      op.push(me[i]);
    } else if (me[i] == '(') {
      op.push(me[i]);
    } else if (me[i] == ')') {
      while (op.top() != '(') {
        cout << op.top();
        op.pop();
      }
      op.pop();
    } else {
      cout << me[i];
    }
  }
  while (!op.empty()) {
    cout << op.top();
    op.pop();
  }

  return 0;
}
```

(복잡도 생략 가능)  
시간 복잡도 : $O(s.size())$  
공간 복잡도 : $O()$   



## 회고(지나치게 간단한 문제는 생략 가능)

### 간단한 풀이와 접근 방식



### 왜 그러한 풀이를 했는지?

표기조작은 보통 스택을 떠올리는게 타당함

### (틀렸다면) 오답 원인

사소한 부분에서 계속 틀려서 오답처리가 됐었다. 현재의 연산자보다 스택 안의 우선순위가 크거나 같을 경우 스택의 연산자를 출력해줘야한다. 즉, 먼저나온 곱하기를 먼저 곱해주고, 곱하기를 더하기보다 먼저해줘야한다.. 이런 얘기가 되겠다.

### (참고했다면) 참고한 코드

#### 왜 저 풀이를 떠올리지 못했을까?

