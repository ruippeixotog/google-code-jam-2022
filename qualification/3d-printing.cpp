#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

#define MAXN 3
#define TGT 1000000
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef long double ld;

int c[MAXN], m[MAXN], y[MAXN], k[MAXN];

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    for(int i = 0; i < 3; i++) {
      scanf("%d %d %d %d\n", &c[i], &m[i], &y[i], &k[i]);
    }

    int minC = *min_element(c, c + 3);
    int minM = *min_element(m, m + 3);
    int minY = *min_element(y, y + 3);
    int minK = *min_element(k, k + 3);

    if(minC + minM + minY + minK < TGT) {
      printf("Case #%d: IMPOSSIBLE\n", tc);
    } else {
      int total = TGT;
      int tgtC = min(total, minC);
      total -= tgtC;
      int tgtM = min(total, minM);
      total -= tgtM;
      int tgtY = min(total, minY);
      total -= tgtY;
      int tgtK = min(total, minK);
      total -= tgtK;

      printf("Case #%d: %d %d %d %d\n", tc, tgtC, tgtM, tgtY, tgtK);
    }
  }
  return 0;
}
