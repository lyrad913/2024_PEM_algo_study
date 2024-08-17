# 1406-에디터

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    list<char> l;
    for(auto a: s) l.push_back(a);
    auto csor = l.end(); //마지막 요소 뒤에 있는 위치를 가리키는 iterator
    int m;
    cin >> m;
    while(m--){
        char cmd;
        cin >> cmd;
        if(cmd == 'L'){
            if(csor != l.begin()) csor--;
        }
        else if(cmd == 'D'){
            if(csor != l.end()) csor++;
        }
        else if(cmd == 'B'){
            if(csor != l.begin()){
                csor--;
                csor = l.erase(csor);
            }
        }
        else if(cmd == 'P'){
            char alp;
            cin >> alp;
            l.insert(csor, alp); //특정 위치 요소 앞에 새로운 요소 삽입
        }
    }
    for(auto a: l) cout << a;
}
```

## 풀이

`std::list`을 사용한다

end() 함수 때문에 헷갈렸는데 이 함수는 리스트의 마지막 원소 뒤에 있는 위치를 가르킨다

## 복잡도

### 시간복잡도

cin >> s : 문자열 입력을 처리하는데 O(N) 시간이 걸린다

cin >> m : 명령어의 수만큼 전체 명령어를 처리하는데 O(M) 걸린다

⇒ O(N+M)

### 공간복잡도

string s, list<char> l → 둘다 O(N)