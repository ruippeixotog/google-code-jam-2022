#include <algorithm>
#include <cstdio>
#include <vector>

#define P 3
#define N 4
#define TGT 1000000

using namespace std;

int ink[N][P];

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    for(int i = 0; i < P; i++) {
      for(int j = 0; j < N; j++) {
        scanf("%d\n", &ink[j][i]);
      }
    }

    int rem = TGT;
    vector<int> comps;
    for(int i = 0; i < N; i++) {
      int comp = min(rem, *min_element(ink[i], ink[i] + P));
      comps.push_back(comp);
      rem -= comp;
    }

    if(rem > 0) {
      printf("Case #%d: IMPOSSIBLE\n", tc);
    } else {
      printf("Case #%d:", tc);
      for(int i = 0; i < N; i++) printf(" %d", comps[i]);
      printf("\n");
    }
  }
  return 0;
}
