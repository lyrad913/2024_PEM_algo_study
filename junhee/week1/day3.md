# [1406-에디터](https://www.acmicpc.net/problem/1406)

한줄짜리 에디터가 있음. 에디터에는 커서 존재. 커서는 글자 사이사이와, 줄 맨 앞, 뒤 가능.
네가지 명령어를 처리하는 에디터 구현.

## 풀이

```cpp
#include <bits/stdc++.h>

using namespace std;

void setting(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

int main(void){
  setting();
  string str;
  cin >> str;

  list<char> content;
  for(char ch: str){
    content.push_back(ch);
  }

  auto cursor = content.end();

  int n_command;
  cin >> n_command;

  for(int i = 0; i < n_command; ++i){
    char command; cin >> command;
    switch (command)
    {
    case 'L':
      if(cursor != content.begin()) --cursor;
      break;
    case 'D':
      if(cursor != content.end()) ++cursor;
      break;
    case 'B':
      if(cursor != content.begin())
        cursor = content.erase(--cursor);
      break;
    case 'P':
      char to_put; cin >> to_put;
      content.insert(cursor, to_put);
      break;
    default:
      break;
    }
  }

  for(char ch : content) cout << ch;
}
```


리스트에 익숙해지기.