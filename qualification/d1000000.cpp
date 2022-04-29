#include <algorithm>
#include <cstdio>

#define MAXN 1000000

using namespace std;

int s[MAXN];

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n; scanf("%d\n", &n);
    for(int i = 0; i < n; i++)
      scanf("%d\n", &s[i]);

    sort(s, s + n);
    int cnt = 0;
    for(int i = 0; i < n; i++) {
      if(s[i] > cnt) cnt++;
    }
    printf("Case #%d: %d\n", tc, cnt);
  }
  return 0;
}
