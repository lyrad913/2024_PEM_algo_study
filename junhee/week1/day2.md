# [10808-알파벳 개수](https://www.acmicpc.net/problem/10808)

## 풀이

```cpp
#include <bits/stdc++.h>

using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  vector<int> alpha(26, 0);
  string word;
  cin >> word;
  for(auto ch : word){
    ++alpha[ch-'a'];
  }
  for(int cnt : alpha){
    cout << cnt << " ";
  }
  return 0;
}
```


(복잡도 생략 가능)  
시간 복잡도 : O(n)  

n : 단어의 길이
 
# [2577-숫자의 개수](https://www.acmicpc.net/problem/2577)

## 풀이

```cpp
#include <bits/stdc++.h>

using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b, c;
  cin >> a >> b >> c;
  
  int mul = a * b * c;
  
  vector<int> ret(10, 0);
  while(mul > 0){
    ++ret[mul % 10];
    mul /= 10;
  }
  for(int i = 0; i < 10; ++i){
    cout << ret[i] << '\n';
  }
}
```
 
# [문제번호-문제이름](문제링크)

## 풀이

```cpp
#include <bits/stdc++.h>

using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n_room;
  cin >> n_room;

  vector<int> tiles(10, 0);
  while(n_room>0){
    ++tiles[n_room % 10];
    n_room /= 10;
  }

  int six_or_nine = 0;
  int max_tiles = 0;
  for(int i = 0; i < 10; ++i){
    if(i == 6 || i == 9){
      six_or_nine += tiles[i];
    } else {
      max_tiles = max_tiles < tiles[i] ? tiles[i] : max_tiles;
    }
  }

  if(six_or_nine % 2 == 1) six_or_nine += 1;
  
  cout << max(max_tiles, six_or_nine / 2);
}
```

(복잡도 생략 가능)  
시간 복잡도 : O(n)  

n : 방 번호의 자릿수  

## 회고(지나치게 간단한 문제는 생략 가능)

### 간단한 풀이와 접근 방식

방번호에서 각 수들의 개수를 저장하는 배열.
6, 9는 상호 대체 가능하기 때문에 따로 처리

최대 등장 횟수와 6, 9 등장 회수 합 / 2 중 더 큰 것을 리턴

### (참고했다면) 참고한 코드

- https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x03/solutions/1475.cpp
- ...

올림을 하면 되기 때문에, 짝/홀을 확인할 필요 없이 그냥 1을 더하고 2로 나누면된다.
 
# [3273-두 수의 합](https://www.acmicpc.net/problem/3273)

## 풀이

```cpp
#include <bits/stdc++.h>

using namespace std;
  

int sol(const vector<int>& seq, const int& sum){
  bool appeared[1000001] = {false, };
  int ret = 0;
  for(auto elem: seq){
    //if(appeared[sum-elem]) ++ret; FIXME: out of bound error
    if(0 < sum - elem && sum - elem < 1000001){ if(appeared[sum-elem]) ++ret;}
    appeared[elem] = true;
  }
  return ret;
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n_seq = 0;
  cin >> n_seq;

  vector<int> seq(n_seq, 0);
  for(int i = 0; i < n_seq; ++i){
    cin >> seq[i];
  }

  int sum;
  cin >> sum;

  cout << sol(seq, sum);
}
```

(복잡도 생략 가능)  
시간 복잡도 : O(n)  

n : 수열의 길이
m : ?

## 회고(지나치게 간단한 문제는 생략 가능)

### 간단한 풀이와 접근 방식

### 왜 그러한 풀이를 했는지? 

문제의 어느 포인트에서 그러한 알고리즘/접근법을 선택하고자 마음 먹었는지 등을 적기.   

### (틀렸다면) 오답 원인

인덱스 연산 시에 빼기는 음수가 나올 수 있다는 점을 유의해야 함.

