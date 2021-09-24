def solution(s):
    lst = list(s)
    p = lst.count('p') + lst.count('P')
    y = lst.count('y') + lst.count('Y')
    if p == y: return True 
    else: return False

print(solution("PyY"))