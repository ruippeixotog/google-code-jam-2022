#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <string>

#define MAXN 100

using namespace std;

string s[MAXN];

bool check(string& str) {
  set<char> seen = {str[0]};
  for(int i = 1; i < str.length(); i++) {
    if(str[i] == str[i - 1]) continue;
    if(!seen.insert(str[i]).second) return false;
  }
  return true;
}

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n; scanf("%d\n", &n);
    for(int i = 0; i < n; i++)
      cin >> s[i];

    for(int i = 0, sep = 0; i < n; i++) {
      if(equal(s[i].begin() + 1, s[i].end(), s[i].begin())) {
        swap(s[sep++], s[i]);
      }
    }

    for(int i = 0; i < n; i++) {
      if(s[i].empty()) continue;

      for(int j = 0; j < n; j++) {
        if(i == j || s[j].empty()) continue;

        if(s[i].back() == s[j].front()) {
          s[i] = s[i] + s[j];
          s[j].clear();
          j = -1;
        }
      }
    }

    string res;
    for(int i = 0; i < n; i++) {
      res += s[i];
    }

    if(!check(res)) {
      printf("Case #%d: IMPOSSIBLE\n", tc);
    } else {
      printf("Case #%d: %s\n", tc, res.c_str());
    }
  }
  return 0;
}
