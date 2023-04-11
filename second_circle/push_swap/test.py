from random import *

n = int(input("몇 개 만들거에요? "))

nums = list(sample(range(-n, n + 1), n))

for n in nums:
    print(n , end = ' ')
print()
