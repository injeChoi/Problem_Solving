def solution(n):
    bn = str(format(n, "b")).count("1")
    
    for num in range(n + 1, 1000001):
        if bn == str(format(num, "b")).count("1"):
            return num