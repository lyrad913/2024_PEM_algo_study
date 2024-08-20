# 2750-수 정렬하기

```cpp
#include <bits/stdc++.h>
using namespace std;
int arr[1000];
int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    for(int i=0; i<n; i++){ // bubble sort
        for(int j=0; j<n-1-i; j++){
            if(arr[j]>arr[j+1]) swap(arr[j], arr[j+1]);
        }
    }
    for(int i=0; i<n; i++) cout << arr[i] << '\n';
}
```

## 풀이

버블 정렬을 이용하여 큰 자료들을 뒤로 이동시킨다

## 복잡도

### 시간

O(N^2)

### 공간

배열 arr를 저장 → O(N)