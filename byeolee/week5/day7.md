# 11780-플로이드2

```cpp
#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int d[101][101]; //최단거리테이블
int nxt[101][101];
int n, m;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++) 
        fill(d[i], d[i]+1+n, INF); //초기화
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c);
        nxt[a][b] = b;
    }
    for(int i=1; i<=n; i++) d[i][i] = 0;
    for(int k=1; k<=n; k++){
        for(int s=1; s<=n; s++){
            for(int t=1; t<=n; t++){
                if(d[s][k] + d[k][t] < d[s][t]){
                    d[s][t] = d[s][k] + d[k][t];
                    nxt[s][t] = nxt[s][k]; //중간 정점 저장(s와 가까운 정점)
                }
            }
        }
    }
    //최단거리 테이블 출력
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(d[i][j]==INF) cout << "0 "; //행렬에 값이 없는 경우
            else cout << d[i][j] << " ";
        }
        cout << '\n';
    }
    //nxt 테이블 출력
    for(int i=1; i<=n; i++){ // i->j
        for(int j=1; j<=n; j++){
            if(d[i][j]==0||d[i][j]==INF){
                cout << "0\n";
                continue;
            }
            vector<int> path;
            int st = i;
            while(st != j){ //j전까지
                path.push_back(st); 
                st = nxt[st][j]; //st와 가까운 정점 
            }
            path.push_back(j);
            cout << path.size() << ' ';
            for(auto x : path) cout << x << ' ';
            cout << '\n';
        }
    }
}
```

## 풀이

출력:

- 도시 i에서 j로 가는데 필요한 최소 비용 → 최단거리 테이블
- 도시 i에서 j로 가는 경로 → nxt 테이블

## 오류(메모리 초과)

m이 큰 경우 nxt 행렬이 메모리를 많이 차지

```cpp
if (condition)
    statement1;
    statement2;
```

위 코드 경우, 조건이 참일 때 실행되는 것은 첫번째 문장만이고 두번째 문장은 조건에 상관없이 항상 실행된다 

따라서 둘다 조건에 따라 실행하고자 한다면 중괄호를 사용하여야 한다

→ 중괄호를 사용하는 것을 빼먹어서 메모리 초과가 걸렸다