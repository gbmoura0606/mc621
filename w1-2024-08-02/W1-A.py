# Longest uncommon prefix

n = int(input())
s = input()

for i in range (1,n):
  acc = 0
  for k in range(1,n-i+1):
    if (s[k-1] == s[k+i-1]):
      break
    acc += 1
  print(acc)

  