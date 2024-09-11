#include <stdio.h>

int getMinimumValue(int N, int K) {
  int nOperations = 0;
  int value = 1;

  while (nOperations < N) {
    if (2 * value > value + K) {
      value = value + K;
    } else {
      value = 2 * value;
    }
    nOperations++;
  }

  return value;
}

int main() {
  int N, K;

  scanf("%d", &N);
  scanf("%d", &K);

  printf("%d", getMinimumValue(N, K));
  return 0;
}
