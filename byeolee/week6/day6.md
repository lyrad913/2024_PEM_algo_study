# 1715-카드정렬하기

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    priority_queue<int, vector<int>, greater<int>> pd;
    int n;
    cin >> n;
    while(n--){ //입력값 저장
        int x;
        cin >> x;
        pd.push(x);
    }
    int sum = 0;
    while(pd.size()>1){
        int a = pd.top(); pd.pop();
        int b = pd.top(); pd.pop();
        sum += a+b;
        pd.push(a+b);
    }
    cout << sum;
}
```

## 풀이

매순간마다 가장 작은 묶음 2개를 하나로 만들면 된다

→ 최솟값 2개를 꺼내서 둘의 합을 더하고 큐에 다시 넣음

먼저 비교해서 합쳐놓은 카드 수가 합쳐지길 기다리는 나머지 카드수보다 작은 경우도 생각해봐야 한다

합쳐지길 기다리는 카드 중 가장 작은 것 두 세트를 계속해서 찾아야 한다

## 복잡도

### 시간복잡도

힙 자료구조는 완전 이진 트리 형태를 가지며 삽입, 삭제 시 특정 순서를 유지하기 위해 재구성 작업이 필요하다

먼저 새로운 요소를 힙의 마지막 위치에 임시로 삽입하고 새로 삽입된 요소가 힙의 규칙을 만족하도록 트리를 재구성한다 → 최악의 경우 트리의 높이만큼의 교환 작업이 필요하고, 트리의 높이는 log n에 비례하기 때문에 삽입 작업의 시간 복잡도는 O(log n)이 된다

입력값 저장: O(NlogN)

합산 작업: 우선순위 큐의 크기가 1이 될 때까지 n-1번 수행 → O(NlogN)

∴ O(NlogN)

### 공간복잡도

우선순위 큐에 n개의 원소가 저장

∴ O(N)