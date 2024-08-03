# [18870-좌표 압축](https://www.acmicpc.net/problem/18870)

## 풀이

```cpp
#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> seq(n);
  for (auto& e : seq) {
    cin >> e;
  }
  vector<int> seq_copy(seq);

  // -10 -9 2 4 4
  sort(seq.begin(), seq.end());

  unordered_map<int, int> cnt;  // value, n_value;

  int prev_value = -1000000001;
  int n_value = 0;

  for (auto it = seq.begin(); it != seq.end(); ++it) {
    if (*it != prev_value) {
      cnt[*it] = n_value++;
      prev_value = *it;
    }
  }

  for (auto it = seq_copy.begin(); it != seq_copy.end(); ++it) {
    cout << cnt[*it] << " ";
  }

  return 0;
}
```

(복잡도 생략 가능)  
시간 복잡도 : $O(n\log n)$  
공간 복잡도 : $O()$   



## 회고(지나치게 간단한 문제는 생략 가능)

### 간단한 풀이와 접근 방식

모든 원소들을 유니크하게 만들고, 자기보다 작은 원소들의 개수를 압축된 좌표로 사용한다.

### 왜 그러한 풀이를 했는지?

배열을 정렬하면 본인 인덱스의 왼쪽은 전부 자기보다 작은 원소이고, 중복되는 원소의 유무만을 고려해주면 되겠다 싶었다.  
또, 읽고 쓰고 탐색하는 것을 $O(1)$에 끝낼 수 있도록 해쉬(`unordered_map`)을 사용하였다.

### (틀렸다면) 오답 원인



### (참고했다면) 참고한 코드

풀어보고, 모범답안과 비교해봤다.

- [예제풀이](https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x13/solutions/18870.cpp)
  
```cpp
// http://boj.kr/ee7936483d9848d9b6a7a14243656eed
#include <bits/stdc++.h>
using namespace std;

int n;
int x[1000005];
vector<int> uni; // unique
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> x[i];
    uni.push_back(x[i]);
  }
  sort(uni.begin(), uni.end());
  uni.erase(unique(uni.begin(), uni.end()), uni.end());
  for(int i = 0; i < n; i++)
    cout << lower_bound(uni.begin(), uni.end(), x[i]) - uni.begin() << ' ';
}
```

#### 왜 저 풀이를 떠올리지 못했을까?

stl에 대한 부족. 조금 더 익숙해질 필요가 있겠다.

- `unique(it1, it2)` : it1~it2까지의 배열(또는 컨테이너 등)에서 연속되는 원소들을 하나로 줄이고, 새로운 끝 지점의 반복자를 반환한다. 
  - ex : {1, 5, 3, 3, 3, 5, 1} ➡️ {1, 5, 3, 5, 1, x(<-return iterator), x}
- `erase(it1, it2)` : [it1, it2)까지의 원소를 제거한다.