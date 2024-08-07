# 11286-절댓값 힙

```cpp
#include <bits/stdc++.h>
using namespace std; 

class cmp{
public:
    bool operator()(int a, int b){ //절댓값이 가장 작은 값이 높은 우선순위
        if(abs(a) != abs(b)) return abs(a) > abs(b); 
        return a > 0 && b < 0; //음수가 높은 우선순위
    }
};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    priority_queue<int, vector<int>, cmp> pd;
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        if(x==0){
            if(pd.empty()) cout << "0\n";
            else{
                cout << pd.top() << '\n';
                pd.pop();
            }
        }
        else pd.push(x);
    }
}
```

## 풀이

### STL priority_queue를 사용

```cpp
priority_queue<int> pd; //<>안에 삽입할 데이터의 자료형을 지정

prioirity_queue<DATA, vector<DATA>, compare> pd;
// <자료형, container, 비교함수> 변수명
// 선언한 자료형 변수들을 비교함수에 따라 정렬하는 우선순위큐를 선언
// 직접 만든 비교 구조체(compare)를 넣을 경우 vector<{data_type}>을 중간에 넣어줘야 한다
```