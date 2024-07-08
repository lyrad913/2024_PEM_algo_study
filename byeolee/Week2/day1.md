# 10828-스택

```cpp
#include <iostream>
#include <stack>
using namespace std;

int main(){
    int n; // 명령어 개수
    cin >> n;

    stack<int> s; //스택
    string cmd; //명령어

    if(n<1||n>10000) return 0;

    for(int i=0; i<n; i++){
        cin >> cmd;
        if(cmd == "push"){
            int num=0;
            cin >> num;
            s.push(num);
        }
        else if(cmd == "pop"){
            if(s.empty()){
                cout << "-1" <<endl;
            }
            else{
                cout << s.top() <<endl;
                s.pop();
            }
        }
        else if(cmd == "size"){
            cout << s.size() <<endl;
        }
        else if(cmd == "empty"){
            if(s.empty()){
                cout << "1" << endl;
            }else{
                cout << "0" << endl;
            }
        }
        else if(cmd == "top"){
            if(s.empty()){
                cout << "-1" << endl;
            } else{
                cout << s.top() << endl;
            }
        }
    }
}
```

총 명령어 개수 n개 → 전체 시간복잡도 O(n)

최악의 경우 모든 명령어가 push일 때 스택에 n개의 요소가 저장될 수 있다 → 공간복잡도 O(n)

(n, cmd, num은 각각 O(1))

stack STL을 사용하면 스택 기본 함수는 어렵지 않게 구현할 수 있다