import sys
from decimal import Decimal, getcontext

getcontext().prec = 60  # Set desired precision

sys.setrecursionlimit(1000000)

# initialize DP table for memoization
C = [[Decimal(0) for _ in range(100)] for _ in range(700)]


def nCr(n, r):
    if n < 0 or r < 0 or n < r:
        return Decimal(0)
    if r == 0 or n == r:
        return Decimal(1)
    if C[n][r] != 0:
        return C[n][r]
    C[n][r] = nCr(n-1, r) + nCr(n-1, r-1)
    return C[n][r]


def main():
    n, a, b = map(int, sys.stdin.readline().split())
    a -= n
    b -= n
    a = max(0, a)

    ans = Decimal(0)
    for i in range(n+1):
        val = Decimal(0)
        for sum_ in range(b, a-1, -1):
            val += nCr(sum_ + n - 1 - 6*i, n - 1)

        if i % 2 == 1:
            ans -= val * nCr(n, i)
        else:
            ans += val * nCr(n, i)

    ans = ans / (Decimal(6) ** n)
    print(f"{ans:.6f}")


if __name__ == "__main__":
    main()
