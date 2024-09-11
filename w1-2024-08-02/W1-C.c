#include <stdio.h>
#include <stdlib.h>

// https://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended/
// Geeks for Geeks: Euclidean algorithms
int gcd(int a, int b) {
  if (a == 0)
    return b;
  return gcd(b % a, a);
}

int getSpacesGcd(int spaces[], int N) {
  int spacesGcd = spaces[0];

  for (int i = 0; i < N - 1; i++) {
    spacesGcd = gcd(spaces[i + 1], spacesGcd);
  }

  return spacesGcd;
}

int main() {
  int N;

  scanf("%d", &N);

  int *trees = (int *)malloc(N * sizeof(int));
  int spaces[N - 1];

  for (int i = 0; i < N; i++) {
    scanf("%d", &trees[i]);
  }

  for (int i = 0; i < N - 1; i++) {
    spaces[i] = trees[i + 1] - trees[i];
  }

  int spacesGcd = getSpacesGcd(spaces, N - 1);
  int treeCount = 0;

  for (int i = 0; i < N - 1; i++) {
    if (spaces[i] > spacesGcd)
      treeCount = treeCount + (spaces[i] / spacesGcd - 1);
  }

  printf("%d", treeCount);

  free(trees);
  return 0;
}
