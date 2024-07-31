# 11404-플로이드

```cpp
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f; //거리가 무한
int d[105][105];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i=1; i<=n; i++) 
        fill(d[i], d[i]+n+1, INF); //무한대로 초기화
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c); //입력 -> 행렬
    }
    for(int i=1; i<=n; i++) d[i][i]=0; //시작과 도착이 같은 경우 없다
    for(int k=1; k<=n; k++){
        for(int s=1; s<=n; s++){
            for(int t=1; t<=n; t++){
                d[s][t] = min(d[s][t], d[s][k]+d[k][t]);
            }
        }
    }
    // 출력
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(d[i][j]==INF) cout << "0 "; //행렬에 값이 없는 경우
            else cout << d[i][j] << " ";
        }
        cout << '\n';
    }
}
```

## 풀이

n개의 도시 = vertex n개 → 최단거리 테이블 n*n 행렬

m개의 버스 = edge m개

버스 중에 시작도시 ~ 도착도시가 같은 버스가 있음 → min 함수 사용해서 입력될 때마다 기존 행렬 값과 비교해야 한다

최단거리 테이블을 만드는 법:

1. 먼저 행렬을 무한대로 초기화한다
2. 중간에 다른 정점을 거치지 않았을 때의 최단거리를 행렬에 저장한다
3. 한번 거쳐가는 최단거리를 1부터 n까지 갱신한다

출력은 행렬에 값이 무한으로 계속 남아있는 경우를 대비하여 무한값일 경우 0을 출력한다

## 복잡도

### 시간

O(N^3)

### 공간

2차원 배열 n*n 

O(N^2)