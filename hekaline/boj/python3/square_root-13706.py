# 고정 소수점 사용
from decimal import Decimal, getcontext

# 소수점 연산 정확도
getcontext().prec = 1000

# 입력값 고정 소수점으로 변환
n = Decimal(input())

# Decimal 제곱근
ans = n.sqrt()

print(int(ans))
