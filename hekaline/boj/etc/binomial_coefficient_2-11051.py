# memo for factorial
memo = [1, 1]

# get factorial 2 to factorial n
n, k = map(int, input().split());
for i in range(2, n + 1):
    memo.append(memo[i-1] * i)

nCk = memo[n] // (memo[n - k] * memo[k])
print(nCk % 10007)
