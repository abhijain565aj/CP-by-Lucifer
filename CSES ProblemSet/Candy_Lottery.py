from decimal import Decimal, getcontext, ROUND_HALF_EVEN

# Set precision high enough
getcontext().prec = 10

n, k = map(int, input().split())
ans = Decimal('0')

for i in range(k, 0, -1):
    k = Decimal(k)
    i = Decimal(i)
    ans += ((i/k)**n)*(1-((i-1)/i)**n)*i
    # Rounding to 6 decimal places with ROUND_HALF_EVEN (banker's rounding)
# print(ans)
ans = ans.quantize(Decimal('0.000001'), rounding=ROUND_HALF_EVEN)
print(ans)
