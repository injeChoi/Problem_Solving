from math import gcd

s = input()
t = input()

GCD = gcd(len(s), len(t))
LCM = len(s) * len(t) // GCD

s *= LCM // len(s)
t *= LCM // len(t)

if s == t: print(1)
else: print(0)
