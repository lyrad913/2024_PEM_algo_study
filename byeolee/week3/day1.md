# 3986-좋은 단어

```cpp
#include <iostream>
#include <stack>
using namespace std;

int main(){
    int n;
    cin >> n;

    int count = 0;
    while(n--){
        string w;
        cin >> w;
        
        stack<char> s;
        for(int i=0; i<w.length(); i++){
            if(s.empty()){
                s.push(w[i]);
            }
            else{
                if(s.top() == w[i]){
                    s.pop();
                }
                else{
                    s.push(w[i]);
                }
            }
        }
        if(s.empty()){
            count++;
        }
    }
    cout << count;
}
```

### 풀이

같은 글자끼리 교차하지 않으면서 쌍을 짓는다 → 수식의 괄호 쌍과 규칙이 같다

입력: 첫줄은 숫자 `int`, 그다음 줄부터는 문자열 `string`을 갖는다

출력: 좋은 단어의 수 `int count`

`while(0)` 은 while문 안의 코드가 실행되지 않는다 

while문으로 n번을 반복 → `while(n--)` 을 이용

한 단어의 알파벳을 stack에 넣기 위해 for문을 사용한다. 한 단어의 알파벳 수만큼 반복한다. 현재의 알파벳을 나타내기 위해서는 string의 배열 성질을 이용한다.

알파벳을 스택에 넣을때 3가지 경우가 발생한다

1. 스택이 비어있을때 (`top` 이 없을때) : 그냥 넣는다 `push`
2. 스택이 비어있지 않을때, `top`값이 현재 탐색한 문자와 일치 : `pop` 
3. 스택이 비어있지 않을때, `top`값이 현재 탐색한 문자와 일치하지 않는다: 현재의 값을 스택에 `push` 한다

만약 좋은 단어라면 스택에 남아있는 알파벳이 없어야 한다

### 오답

`cout << count` 에서 빨간 줄이 가면서 error가 발생

`count` 을 while문 밖에서 사용하면서 while문 안에서 선언하여 오류가 발생하였다