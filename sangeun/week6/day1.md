# [2108-통계학](https://www.acmicpc.net/problem/2108)

## 풀이

```cpp
#include<iostream>
#include<algorithm>
#include<cmath>
#include<climits>
#include<vector>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<int> num(n);
  vector<int> count(8001, 0);  // 음수를 포함한 카운트 배열 초기화
  int sum = 0;

  for(int i = 0; i < n; i++){
    cin >> num[i];
    sum += num[i];
    count[4000 + num[i]]++;  // 음수를 포함한 카운트 배열
  }

  // 산술평균
  double mean = round(double(sum)/n);
  if (mean == -0) mean = 0;
  cout << mean << '\n';

  // 중앙값
  sort(num.begin(), num.end());
  cout << num[n / 2] << '\n';

  // 최빈값
  int max_count = 0;
  for(int i = 0; i < 8001; i++){
    if(count[i] > max_count)
      max_count = count[i];
  }

  vector<int> modes;
  for(int i = 0; i < 8001; i++){
    if(count[i] == max_count)
      modes.push_back(i - 4000);
  }

  // 여러 개 있을 경우 두 번째로 작은 값 출력
  if(modes.size() == 1) {
    cout << modes[0] << '\n';
  } else {
    sort(modes.begin(), modes.end());
    cout << modes[1] << '\n';
  }

  // 범위
  cout << num[n - 1] - num[0] << '\n';

  return 0;
}

```

(복잡도 생략 가능)  
시간 복잡도 : O(n) + O(1) + O(nlogn) + O(1) + O(1) = O(nlogn) \\
             입력    평균    중앙값    최빈값  범위

n : 입력 크기
## 회고(지나치게 간단한 문제는 생략 가능)
round시 -0이 나올 수 있다. 
### 간단한 풀이와 접근 방식
산술평균 중앙값 범위는 쉽고 최빈값만 풀이\\
최빈값은 count배열의 인덱스를 사용하기로 했는데 인덱스는 양수이므로 8000크기의 배열을 사용하여 4000인덱스부터 bias를 통해 음수도 count하는 전략 사용
### 왜 그러한 풀이를 했는지? 
부동소수점 표기법이 기억이 났다
문제의 어느 포인트에서 그러한 알고리즘/접근법을 선택하고자 마음 먹었는지 등을 적기.   

### (틀렸다면) 오답 원인
99%에서 계속 틀리길래 예시입력중에 산술평균이 -0.5일 때 반올림을하면 -0으로 출력되는 경우를 발견했다. 
이는 round함수가 완벽한 반올림을 해주는 것이 아니라 아주 작은 수로 변환하기 때문에 -0.5가 -0.000000001 로 되어 -0이 출력 되는 것이다. 
따라서 예외처리를 통해 이부분을 해결하니 통과했다. 
### (참고했다면) 참고한 코드

- [코드](링크)
- ...

간략한 해설

#### 왜 저 풀이를 떠올리지 못했을까?

다음에 저런 풀이를 떠올리려면?

---

## 참고

[알고리즘 문제 해결 전략 세트](https://product.kyobobook.co.kr/detail/S000001032946)에서 적당히 저한테 도움이 될 것 같은 형식으로 번형했습니다. 템플릿을 만든 이유는 단순히 문풀에서 끝나는게 아니라, 뭔가 남았으면 좋겠어서 만들어봤습니다. 
그러나 저는 늘상 문풀에는 약했기 때문에... 아마 도움이 안 될 수도 있을 것 같습니다.
다른 방식의 접근이 좋겠다라고 생각하시면 다른 템플릿을 사용하셔도 무방합니다. 책에서 제시하는 문제 해결 알고리즘 은 아래와 같습니다.

> 1. 문제를 읽고 이해한다.
> 2. 문제를 익숙한 용어로 재정의한다.
> 3. 어떻게 해결할지 계획을 세운다.
> 4. 계획을 검증한다.
> 5. 프로그램으로 구현한다.
> 6. 어떻게 풀었는지 돌아보고, 개선할 방법이 있는지 찾아본다.

저는 6에 중점을 두어 템플릿을 만들었습니다.  

### 문제 해결 전략

체계적인 접근을 위한 질문

> 1. 비슷한 문제를 풀어본 적이 있나?
> 2. Brute-force?
> 3. 문제 푸는 과정을 수식화 할 수 있나?
> 4. 문제를 단순화 할 수 있나?(ex. 2d좌표 -> 1d 좌표)
> 5. 그림으로 그려볼 수 있나?
> 6. 문제를 수직으로 표현할 수 있나?
> 7. 문제를 분해/변형할 수 있나?(ex. 제약 조건 분리)
> 8. 역으로 생각할 수 있나?(ex. 사다리게임에서 꽝을 피하는 번호는?)
> 9. 순서를 강제할 수 있나?
> 10. 특정 형태의 답만을 고려할 수 있나?

 
