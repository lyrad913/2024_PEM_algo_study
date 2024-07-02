m# 2577-숫자의 개수

세 개의 자연수 A, B, C가 주어질 때 A × B × C를 계산한 결과에 0부터 9까지 각각의 숫자가 몇 번씩 쓰였는지를 구하는 프로그램을 작성하시오.

예를 들어 A = 150, B = 266, C = 427 이라면 A × B × C = 150 × 266 × 427 = 17037300 이 되고, 계산한 결과 17037300 에는 0이 3번, 1이 1번, 3이 2번, 7이 2번 쓰였다.

## 풀이

```cpp
#include <iostream>
#include <string>
using namespace std;

int main(){
    int a, b, c, n;
    cin >> a >> b >> c;
    n = a * b * c;
    string s = to_string(n);
    int num[10] = {0, };
    for(int i=0; i<s.length(); i++){
        num[s[i] - '0'] += 1;
    }
    for(int j=0; j<10; j++){
        cout << num[j] << endl;
    }
}
```

그 전 문제와 동일하게 배열의 인덱스를 사용하여 글자의 개수를 세었다

하지만 그 전 문제에서는 개수를 세는 대상이  `string` 이었고 지금은 `int` 이기 때문에

`int` 를 `string` 으로 바꾸어야 한다 (자료형 변환)

그 다음 string 클래스 객체의 배열을 사용하여 한 문자씩 접근한다

출력이 이상하게 나와서 자세히 봤더니 글자 수를 저장할 배열을 0으로 초기화하지 않았다

⇒ `int num[10] = {0,}` 으로 고침
