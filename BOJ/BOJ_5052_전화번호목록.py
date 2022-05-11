'''
https://www.acmicpc.net/problem/5052

1. 전화번호들을 딕셔너리로 저장한다
2-1. 각각의 전화번호의 일부분이 딕셔너리에 저장돼 있으면 NO를 출력한다
2-2. 온전한 전화번호는 무조건 딕셔너리에 저장돼 있으므로 온전한 전화번로는 검색하지 않는다
3. 모든 전화번호의 앞 부분이 딕셔너리에 저장 안 된 경우 YES를 출력한다

다른 풀이 방법:
전화번호는 문자열이므로 문자열을 정렬하면 1~9까지 순서대로 정렬이 된다
A 문자열이 B 문자열보다 길고 B 문자열의 길이가 3이라 할 때, 
A[:3] = B 라면 A가 B 뒤에 정렬되게 된다 
 
이러한 정렬의 특성을 생각할 때, 
만약 i번째 문자열이 i+1번째 문자열의 앞 부분과 일치한다면 NO를 출력하면 된다 
'''

T = int(input())

def solution():
    n = int(input())
    numbers = [input() for _ in range(n)]
    d = {number: 1 for number in numbers}
    
    for number in numbers:
        for i in range(len(number)-1):
            tmp = number[:i+1]
            try:
                if d[tmp]:
                    print("NO")
                    return
            except:
                continue
    
    print("YES")

for _ in range(T):
    solution()
