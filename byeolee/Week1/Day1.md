# 10808-알파벳 개수

알파벳 소문자로만 이루어진 단어 S가 주어진다. 각 알파벳이 단어에 몇 개가 포함되어 있는지 구하는 프로그램을 작성하시오

## 풀이

```cpp
#include <iostream>
using namespace std;

int main(){
    string word;
    int alp[26] = {0, };
    cin >> word;

    for(int i=0; i < word.length(); i++){
        alp[word[i] - 97] += 1;
    }
    for(int j=0; j < 26; j++){
        cout << alp[j] << ' ';
    }
}
```

단어를 넣을 string, 알파벳을 넣을 alp 배열을 초기화

먼저 alp 배열 출력하는 for문을 만들고 alp 배열에 값을 저장하는 for문을 만들었다

‘a’의 ascii 값이 97인 것을 기억하여 string의 알파벳에 97을 빼서 alp 배열의 index를 설정했다 (반복은 글자 수만큼)