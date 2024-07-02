#include <iostream>
#include <vector>

using namespace std;
using std::vector;

int main()
{
  // 배열은 고정크기의 컨테이너기 때문에 항상 size를 지정해야 했다면
  // 벡터는 필요할 때 마다 메모리를 증가시켜 할당할 수 있음

  vector<int> v1{1,2,3,4,5}; // 동적 메모리가 할당된다. 즉 malloc으로 할당
  vector<int> v2(3); // 소괄호로 초기화를 주면 기본값(0)으로 초기화 된 3개의 원소를 가지는 vector v2 생성
  vector<int> v3(5,2); // 2로 초기화된 5개의 원소를 가지는 vector v3를 생성
  vector<int> v4(v2); // v4는 vector v2를 복사해서 생성

  // 범위 지정으로 벡터 출력
  for(const auto& at : v1) // 메모리를 공유해서 출력해야 복사 오버헤드가 생기지 않음
    cout << at << " ";
    cout << endl;

  for (const auto& at : v2)
    cout << at << " ";
    cout << endl;

  return 0;
}