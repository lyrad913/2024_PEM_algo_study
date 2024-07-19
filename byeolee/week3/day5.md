# 1780-종이의 개수

```cpp
#include <iostream>
using namespace std;

int arr[2187][2187];
int con_1=0, con0=0, con1=0;
bool same(int x, int y, int n){ // (x,y)는 시작위치, n*n으로 한꺼번에 살펴본다
    int num = arr[x][y];
    for(int i=x;i<x+n;i++){
        for(int j=y;j<y+n;j++){
            if(num != arr[i][j]) return false;
        }
    }
    return true;
}
void div(int x, int y, int n){
    if(same(x,y,n)){
        if(arr[x][y]==-1) con_1++;
        else if(arr[x][y]==0) con0++;
        else if(arr[x][y]==1) con1++;
    }
    else{
        int d = n/3; // 변을 1/3으로 나눔
        for(int i=0; i<3; i++){ // 9개로 나누기 때문에 
            for(int j=0; j<3; j++){ // 확인할 행렬은 한변에 3번씩 반복
                div(x+i*d, y+j*d, d);
            }
        }
    }
}
int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    div(0,0,n);
    cout << con_1 << '\n'<< con0 << '\n' << con1;
}
```

## 풀이

어떤 방식으로 재귀를 할 것인지가 중요하다

같은 크기의 종이로 9개 자르면 N/3×N/3 크기의 행렬이 만들어질 것이다

한 **시작 위치 (x,y)**를 중심으로 그 위치에서 주변 N/3×N/3크기의 행렬이 모두 같은 수로 되어 있는지 확인한다

그리고 그 다음으로 확인할 행렬은 (x+N/3, y+N/3)를 **시작**으로 그 주변 N/3×N/3크기의 행렬이다

→ 이런 식으로 재귀를 만든다

## 복잡도

### 시간복잡도

`same` : 최악의 경우, 함수는 전체 행렬의 모든 원소를 확인 → O(N^2)

`div` : same이 false라면 행렬을 9개의 n/3 * n/3 크기의 부분 행렬로 나누어 재귀적으로 호출한다

재귀는 9번 호출되므로, 다음과 같다

$$
T(N) = 9T(N/3) + O(N^2) 
$$

점화식으로 표현되는 재귀 알고리즘의 시간 복잡도를 계산하는 것은 어렵기 때문에 Master theorem을 사용한다

∴ T(n) = O(N^2logN)

### 공간복잡도

`arr` : n*n 행렬 → O(N^2)

`con_1`, `con0`, `con1` : 고정된 크기의 변수 → O(1)

재귀 호출: 

시작 할 때 n*n 행렬을 처리

행렬이 동일하지 않다면, 9개의 n/3*n/3 부분 행렬로 분할

각 호출에서 행렬의 크기를 n/3, n/(3^2), n/(3^3) 크기로 줄어든다

n/(3^k) = 1이 될 때 까지 재귀한다면 k = log3(n)이 된다 → O(logN)

∴ O(1) + O(N^2) + O(logN) = O(N^2)