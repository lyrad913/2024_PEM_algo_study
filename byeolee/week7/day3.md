# 21940-가운데에서 만나기

```cpp
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int d[201][201];
int n,m,k,city[201];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i!=j) d[i][j] = INF;
        }
    }
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c);
    }
    cin >> k;
    for(int i=1; i<=k; i++){
        cin >> city[i];
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
    //조건을 만족하는 도시 x
    int min = INF;
    vector<int> x;
    for(int i=1; i<=n; i++){
        int ans=0; //왕복시간
        for(int j=1; j<=k; j++){
            if(d[i][city[j]] != INF && d[city[j]][i] != INF){
                //i의 왕복시간들 중 최대
                ans = max(d[i][city[j]]+d[city[j]][i], ans); 
            }
        }
        if(min>ans){ //최대가 최소가 되는
            x.clear();
            x.push_back(i);
            min = ans;
        }
        else if(min==ans){
            x.push_back(i); //도시x가 여러개
        }
    }
    //오름차순으로 출력
    sort(x.begin(), x.end());
    for(int i=0; i<x.size(); i++){
        cout << x[i] << " ";
    }
}
```

## 런타임에러

입력 크기가 달라서 에러가 걸렸다

## 오답

for문 괄호를 헷갈리지 않도록 주의