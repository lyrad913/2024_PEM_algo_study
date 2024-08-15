# 14938-서강그라운드

```cpp
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int d[101][101];
int n, m, r, a, b, l, sum, item;
int city[101];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> r;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i!=j) d[i][j] = INF;
        }
    }
    for(int i=1; i<=n; i++) cin >> city[i]; //아이템 갯수 저장
    //길 길이
    for(int i=1; i<=r; i++){
        cin >> a >> b >> l;
        d[a][b] = l;
        d[b][a] = l; // 양 방향
    }
    //플로이드
    for(int i=1; i<=n; i++) d[i][i] = 0;
    for(int k=1; k<=n; k++){ 
        for(int s=1; s<=n; s++){
            for(int t=1; t<=n; t++){
                if(d[s][k] + d[k][t] < d[s][t]){
                    d[s][t] = d[s][k] + d[k][t];
                }
            }
        }
    }
    for(int i=1; i<=n; i++){
        sum = city[i]; //시작
        for(int j=1; j<=n; j++){
            if(i != j && d[i][j] <= m) sum += city[j]; 
            //i=j는 이미 할당되어 있으므로 안됨
        }
        item = max(item, sum);
    }
    cout << item;
}
```

## 풀이

최단 거리 행렬을 만든 후 거리가 m 이하인 곳들 아이템들을 더한다