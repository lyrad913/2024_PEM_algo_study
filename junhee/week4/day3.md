# [1003-피보나치 함수](https://www.acmicpc.net/problem/1003)


## 풀이

```cpp
#include <bits/stdc++.h>

using namespace std;

int cache[41]; 


int fibonacci(int n)
{
    //base case;
    if(n == 0 || n == 1) return cache[n] = n;
    int & ret = cache[n];
    if(ret != -1) return ret;
    return ret = fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    for(int i = 0; i < T; ++i)
    {
        memset(cache, -1, sizeof(cache));
        int n; cin >> n;
        fibonacci(n);
        if(n == 0)
            cout << 1 << " " << 0 << '\n';
        else if(n == 1)
            cout << 0 << " " << 1 << '\n';
        else 
            cout << cache[n-1] << " " << cache[n] << '\n';
    }
}
```

## 회고(지나치게 간단한 문제는 생략 가능)