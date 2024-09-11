#include <stdio.h>
#include <stdlib.h>

// https://cp-algorithms.com/data_structures/disjoint_set_union.html
// disjoint set union - Algorithms for Competitive Programming
int find_set(int v, int *parent) {
  if (v == parent[v])
    return v;
  return parent[v] = find_set(parent[v], parent);
}

void union_sets(int a, int b, int *parent) {
  a = find_set(a, parent);
  b = find_set(b, parent);
  if (a != b)
    parent[b] = a;
}

int getMinimumCost(int N, int M, int x[], int y[]) {
  int cost = 0;
  int *parent = (int *)malloc(N * sizeof(int));

  for (int i = 0; i < N; i++) {
    parent[i] = i;
  }

  for (int i = 0; i < M; i++) {
    if (find_set(x[i] - 1, parent) != find_set(y[i] - 1, parent)) {
      union_sets(x[i] - 1, y[i] - 1, parent);
    }
  }

  for (int i = 0; i < N; i++) {
    if (find_set(i, parent) == i) {
      cost++;
    }
  }

  free(parent);
  return cost;
}

int main() {
  int N, M;

  scanf("%d %d", &N, &M);

  int *x = (int *)malloc(M * sizeof(int));
  int *y = (int *)malloc(M * sizeof(int));

  for (int i = 0; i < M; i++) {
    scanf("%d %d %*d", &x[i], &y[i]);
  }

  printf("%d", getMinimumCost(N, M, x, y));

  free(x);
  free(y);
  return 0;
}
