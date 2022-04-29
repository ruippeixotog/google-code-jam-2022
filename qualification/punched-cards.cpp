#include <cstdio>

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int r, c; scanf("%d %d\n", &r, &c);

    printf("Case #%d:\n", tc);
    for(int i = 0; i < r; i++) {
      printf(i == 0 ? "." : "+");
      for(int j = 0; j < c; j++) {
        printf(i == 0 && j == 0 ? ".+" : "-+");
      }
      printf("\n");

      printf(i == 0 ? "." : "|");
      for(int j = 0; j < c; j++) {
        printf(".|");
      }
      printf("\n");
    }
    printf("+");
    for(int j = 0; j < c; j++) {
        printf("-+");
    }
    printf("\n");
  }
  return 0;
}
