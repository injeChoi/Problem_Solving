'''
https://www.acmicpc.net/problem/11478

부분 문자열을 어떻게 만들 것인가
문제 명세대로 
0, 1, 2, 3, 4, 5, 
0~1, 1~2, ... , 4~5,
0~2, 1~3, 2~4, ...
이런식으로 부분 문자열으 만들어도 되지만
결국 시간 복잡도는 O(N^2)이다
(아래 코드)

문제 명세 말고 단순히
i: 0 ~ 5
j: i ~ 5 
이렇게 순회하면서 부분문자열을 만들어도 결국 시간복잡도는 똑같이 O(N^2)이다

문제 명세대로 충실히 구현하느라 시간을 쏟기보단 
시간 복잡도를 고려하여 빠르게 답을 찾는게 중요하다 
'''

S = input()
tmp = set()

for i in range(1, len(S)):
    for j in range(len(S) - i + 1):
        substring = S[j:j+i]
        tmp.add(substring)

print(len(tmp) + 1)
        