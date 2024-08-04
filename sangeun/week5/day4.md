# [10814-나이순 정렬](https://www.acmicpc.net/status?user_id=gad05216&problem_id=10814&from_mine=1)

## 풀이

```cpp
#include<iostream>
#include<utility>  // for pair
#include<string>   // for string
#include<algorithm> // for sort()
using namespace std;

bool compare(const pair<int, string>& a, const pair<int, string>& b) {
  return a.first < b.first;  // first 기준 오름차순 정렬만
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n; 
  cin >> n;
  pair<int, string> data[100000];

  for (int i = 0; i < n; i++) {
    cin >> data[i].first >> data[i].second;
  }

  stable_sort(data, data + n, compare);

  for (int i = 0; i < n; i++) {
    cout << data[i].first << ' ' << data[i].second << "\n";
  }

  return 0;
}

```


(복잡도 생략 가능)  
시간 복잡도 : O(nlonn)  

n : 입력 크기 N

## 회고(지나치게 간단한 문제는 생략 가능)
stl sort는 stable sort가 아니다! stable sort는 따로 있다.
### 간단한 풀이와 접근 방식
간단한 정렬 문제이다. pair또는 튜플로 존재하는 데이터에서 첫번째 원소에 한해서만 정렬, 첫번째 원소가 같은 경우 입력된 순서대로 출력해야 한다. 
pair는 기본적으로 첫번째 원소를 오름차순으로 첫번째 원소가 같으면 두번째원소를 비교하는 순으로 했기 때문에 compare()를 새로 정의해서 sort에 넘겨주었다. 

### 왜 그러한 풀이를 했는지? 

입력한 순으로 출력하는 것을 따로 정렬하지 않으면 그대로 출력한다고 생각했다

### (틀렸다면) 오답 원인
위 풀이대로 수행이 되려면 sort함수가 stable정렬이어야 하는데 non-stable함수인것을 간과했다. stable_sort()를 따로 작성하니 코드가 통과했다. 
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

 
