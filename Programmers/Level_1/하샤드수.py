def solution(x):
    s = sum(map(int, str(x)))
    return True if x % s == 0 else False 
