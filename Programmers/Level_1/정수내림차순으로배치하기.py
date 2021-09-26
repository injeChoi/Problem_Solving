def solution(n):
    return int(''.join(sorted(str(n), reverse=True)))

solution(938)