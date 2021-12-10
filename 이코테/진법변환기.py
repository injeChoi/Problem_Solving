def convert(i, n):
    T = "0123456789ABCDEF"
    q, r = divmod(i, n)
    if q == 0:
        return T[r]
    else:
        return convert(q, n) + T[r]

print(convert(10, 3))