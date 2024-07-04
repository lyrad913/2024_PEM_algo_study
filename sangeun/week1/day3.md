# [4153-직각삼각형](https://www.acmicpc.net/problem/4153)

## 풀이

```cpp
#include <iostream>
#include <algorithm> // std::sort 사용을 위함
using namespace std;

int main() 
{
    int input[3];
    while (true) {
        for (int i = 0; i < 3; i++) { // 입력에 들어오는 3개의 값을 저장
            cin >> input[i];
        }    
        
        if ((input[0] == 0) && (input[1] == 0) && (input[2] == 0))
            break;
        
        // 세 변의 길이를 오름차순으로 정렬
        sort(input, input + 3);
        
        // 직각 삼각형인지 확인
        if ((input[0] * input[0] + input[1] * input[1]) == input[2] * input[2]) {
            cout << "right" << endl;
        } else {
            cout << "wrong" << endl;
        }
    }
    
    return 0;
}

```

(복잡도 생략 가능)  

## 회고(지나치게 간단한 문제는 생략 가능)
한 줄에 공백을 포함한 입력을 어떻게 받을 것인지에 대한 고민이 본 문제 보다 더 걸렸다. 여러 예외가 있을 텐데..입력을 더 효율적으로 받을 수 있을 것 같은데 혼자 더 고민해보고 나서 구글링 해봐야 겠다.    
### 간단한 풀이와 접근 방식
아는 문법만을 써서 size가 3인 배열에 입력을 저장했다.
입력을 배열에 저장하기만 하면 그 뒤는 조건에 맞게 if문을 통해 피타고라스 정리 공식에 대입만 하면 되기 때문에 쉽다.
### 왜 그러한 풀이를 했는지? 


 
