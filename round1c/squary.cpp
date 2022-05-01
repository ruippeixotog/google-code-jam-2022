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

#define MAXN 2000
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef long double ld;

int e[MAXN];

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n, k; scanf("%d %d\n", &n, &k);
    for(int i = 0; i < n; i++)
      scanf("%d\n", &e[i]);

    ll sum = 0, sumSq = 0;
    for(int i = 0; i < n; i++) {
      sum += e[i];
      sumSq += e[i] * e[i];
    }

    if(sum == 0 && sumSq == 0) {
      printf("Case #%d: 1\n", tc);
    } else if(sum == 0) {
      printf("Case #%d: IMPOSSIBLE\n", tc);
    } else if((sumSq - sum * sum) % (2 * sum) == 0) {
      printf("Case #%d: %lld\n", tc, (sumSq - sum * sum) / (2 * sum));
    } else {
      printf("Case #%d: IMPOSSIBLE\n", tc);
    }
  }
  return 0;
}
