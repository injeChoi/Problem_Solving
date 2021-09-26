def solution(n):
    s = n**(1/2)
    if s - int(s) == 0:
        return (int(s)+1)**2
    else:
        return -1

solution(16)