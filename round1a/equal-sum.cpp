#include <cstdio>
#include <cstdlib>
#include <vector>

#define N 100

using namespace std;

typedef long long ll;

int a[N], b[N];

void initA() {
  for(int i = 0; i < N - 30; i++) {
    a[i] = 300 + i;
  }
  for(int i = 0; i < 30; i++) {
    a[N - 30 + i] = 1 << (29 - i);
  }
}

int readN() {
  int ans; scanf("%d", &ans);
  if(ans == -1) exit(0);
  return ans;
}

void sendA() {
  for(int i = 0; i < N; i++) {
    printf(i ? " %d" : "%d", a[i]);
  }
  printf("\n");
  fflush(stdout);
}

void readB() {
  for(int i = 0; i < N; i++) {
    scanf("%d", &b[i]);
    if(b[i] == -1) exit(0);
  }
}

void sendAns(vector<int>& ans) {
  for(int i = 0; i < ans.size(); i++) {
    printf(i ? " %d" : "%d", ans[i]);
  }
  printf("\n");
  fflush(stdout);
}

int main() {
  initA();

  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    readN();
    sendA();
    readB();

    ll leftSum = 0, rightSum = 0;
    vector<int> left;
    for(int e : b) {
      if(leftSum < rightSum) left.push_back(e);
      (leftSum < rightSum ? leftSum : rightSum) += e;
    }
    for(int e : a) {
      if(leftSum < rightSum) left.push_back(e);
      (leftSum < rightSum ? leftSum : rightSum) += e;
    }
    sendAns(left);
  }
  return 0;
}
