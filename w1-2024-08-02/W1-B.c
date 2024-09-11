#include <stdio.h>

int maxDivisor(int p, int q) {
  for (int i = q; i > 0; i--) {
    if (p % i == 0)
      return i;
  }
}

int getSequenceGcd(int n, int m) {
  int maxGcd = m / n; // melhor caso: todas as parcelas de mesmo valor
  int gcd = maxDivisor(m, maxGcd); // maior divisor de m menor ou igual ao teto

  return gcd;
}

int main() {
  int N, M;

  scanf("%d %d", &N, &M);
  printf("%d", getSequenceGcd(N, M));

  return 0;
}
