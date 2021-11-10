def solution(numbers):
    numbers = list(map(str, numbers))
    # 원소들을 최소 3자리 숫자로 맞춘다, ex) 20 -> 2020, 3 -> 333
    # 동일한 패턴의 문자열들의 대소를 비교하기 위함, ex) 3, 30 -> 333, 303030, 고로 3을 먼저 사용
    numbers.sort(key=lambda x: x * 3, reverse=True)
    return str(int(''.join(numbers)))

solution([221,2,10])