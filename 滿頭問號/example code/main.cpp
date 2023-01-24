#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int P[100000] = {}, Pn = 0;
int cnt;

struct node {
  int C, L;
} dp[1000100];

void pnt(int x) {
  if (!x)
    return;

  int y = dp[x].L;
  pnt(y);

  if (x - y == 1) {
    printf("A");
  } else if (x - y == -1) {
    printf("D");
  } else {
    printf("C");
    for (int i = x / y; i > 1; i--)
      printf("V");
  }
  return;
}

int main() {
  for (int i = 2; i < 1000100; i++) {
    int isPrime = 1;
    int sqrti = sqrt(i);
    for (int j = 0; j < Pn && P[j] <= sqrti; j++) {
      if (i % P[j] == 0) {
        isPrime = 0;
      }
    }
    if (isPrime)
      P[Pn++] = i;
  }
  dp[1] = (node){1, 0};
  for (int i = 2; i < 1000100; i++) {
    dp[i] = (node){dp[i - 1].C + 1, i - 1};
    const int sqrti = sqrt(i);
    for (int j = 0; j < Pn && P[j] <= sqrti; j++) {
      if (i % P[j] == 0) {
        int t = dp[P[j]].C + i / P[j];
        if (dp[i].C > t) {
          dp[i] = (node){t, P[j]};
        }

        t = dp[i / P[j]].C + P[j];
        if (dp[i].C > t) {
          dp[i] = (node){t, i / P[j]};
        }
      }
    }

    if (dp[i - 1].C >= dp[i].C + 1) {
      dp[i - 1] = (node){dp[i].C + 1, i};
    }
  }

  int q;
  scanf("%d", &q);
  pnt(q);
  return 0;
}
