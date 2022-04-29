#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    string s; getline(cin, s);

    string res;
    char curr = 0; int cnt = 0;
    for(int i = 0; i < s.length(); i++) {
      if(s[i] == curr) { cnt++; continue; }

      res += string(curr < s[i] ? cnt * 2 : cnt, curr);
      curr = s[i];
      cnt = 1;
    }
    res += string(cnt, curr);

    printf("Case #%d: %s\n", tc, res.c_str());
  }
  return 0;
}
