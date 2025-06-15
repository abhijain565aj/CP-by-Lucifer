from decimal import Decimal, getcontext, ROUND_HALF_EVEN

# Set precision high enough
getcontext().prec = 30

n = int(input())
a = list(map(Decimal, input().split()))

ans = Decimal('0')

for i in range(n):
    for j in range(i + 1, n):
        count = Decimal('0')
        k = Decimal('1')
        while k <= a[i]:
            count += min(k - 1, a[j])
            k += 1
        ans += count / (a[i] * a[j])

# Rounding to 6 decimal places with ROUND_HALF_EVEN (banker's rounding)
ans = ans.quantize(Decimal('0.000001'), rounding=ROUND_HALF_EVEN)
print(ans)
