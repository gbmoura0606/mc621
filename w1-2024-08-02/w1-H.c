#include <stdio.h>
#include <stdlib.h>

int main() {
  int N;

  scanf("%d", &N);

  int *a = (int *)malloc(N * sizeof(int));
  int *b = (int *)malloc(N * sizeof(int));
  int sum[N];

  for (int i = 0; i < N; i++) {
    scanf("%d %d", &a[i], &b[i]);
  }

  for (int i = 0; i < N; i++) {
    sum[i] = a[i] + b[i];
    printf("%d\n", sum[i]);
  }

  free(a);
  free(b);
  return 0;
}
