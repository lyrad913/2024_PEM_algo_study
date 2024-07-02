
# [1181-단어 정렬](https://www.acmicpc.net/problem/1181)

## 풀이

```cpp
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

//비교 수행하는 함수, qsort의 4번째 인자
int compare(const void* arg1, const void* arg2) 
{   //길이순 정렬
	if (strlen((const char*)arg1) > strlen((const char*)arg2)) return 1;
	else if (strlen((const char*)arg1) < strlen((const char*)arg2)) return -1;
	//길이 같으면 사전순
	else return strcmp((char*)arg1, (char*)arg2);
} 
int main(void)
{    
	int size, length = 51;
	char arr[20000][51] = { 0 };
	scanf("%d", &size);

	for (int i = 0; i < size; i++)      
		scanf("%s", arr[i]);

	//정렬
	qsort(arr, size, sizeof(arr[0]), compare);
	
	//정렬 후 같은 문자열은 생략하고 출력
	for (int i = 0; i < size; i++) {
		if (strcmp(arr[i], arr[i+1]) != 0 || i == size - 1)
			printf("%s\n", arr[i]);
	}
	return 0;
}
```
(복잡도 생략 가능)  
시간 복잡도 : O(nlogn)  
~~공간 복잡도 : O(n^2)~~

n : 입력 문자열 수

## 회고(지나치게 간단한 문제는 생략 가능)
알고리즘 공부를 위해 머지소트로 구현해보려 했으나 시간초과결과가 떠서 그냥 algorithm sort함수 쓰기로 했습니다. 
### 간단한 풀이와 접근 방식
sort함수에 필요한 compare함수를 문제조건에 맞게 설정하는 것이 문제 포인트 \\
길이 비교 먼저 해서 길이가 같으면 사전식 순서 비교 길이가 다르면 길이 비교
### 왜 그러한 풀이를 했는지? 

### ~~(틀렸다면) 오답 원인~~

### (참고했다면) 참고한 코드

- [1181-단어 정렬]([링크](https://aorica.tistory.com/104))
```
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compareWith(string a, string b){
  if(a.length() == b.length())
    return a<b;
  return a.length()<b.length();
}

int main(){
  int N;
  vector<string> vec;  
  cin>>N;
  for(int i=0; i<N; i++){
    string str;
    cin>>str;
    if(find(vec.begin(), vec.end(), str) == vec.end())
      vec.push_back(str);
  }
  sort(vec.begin(), vec.end(), compareWith);

  for(int i=0; i<vec.size(); i++){
    cout<<vec[i]<<'\n';
  }
}
```

### 간략한 해설
입력에 대해 동적으로 메모리를 할당받기 위해 vector를 썼다. 

### ~~왜 저 풀이를 떠올리지 못했을까?~~


### 다음에 저런 풀이를 떠올리려면?
입력을 동적으로 할당할 생각을 먼저 해야 하고 vector를 떠올려야 한다.



 
