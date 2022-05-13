'''
https://www.acmicpc.net/problem/20413

괜히 너무 어렵게 생각해서 더 꼬인 문제
명세를 단순 명료하게 이해하는게 중요했다

주어진 등급에서 과금할 수 있는 돈의 최대치와 저번달에 쓴 돈을 빼면 
이번 달에 주어진 등급에 도달하기 위해 과금할 수 있는 돈의 양이 나온다 

고로 이번 달에 얼마를 쓰게되는지 따로 저장하고
매달 쓴 돈의 총 합은 따로 계산한다 

도달 등급이 D 등급인 경우, 
D 등급에 도달하기 위한 돈 만큼 그냥 때려부을 수 있으므로 
누적을 구할 필요 없이 D 등급 달성을 위한 금액을 부으면 된다 
'''

N = int(input())
S, G, P, D = list(map(int, input().split()))
grades = input()
answer, acc = 0, 0

for grade in grades:
    if grade == 'B':
        acc = S - 1 - acc
        answer += acc
    elif grade == 'S':
        acc = G - 1 - acc
        answer += acc
    elif grade == 'G':
        acc = P - 1 - acc
        answer += acc
    elif grade == 'P':
        acc = D - 1 - acc
        answer += acc
    else:
        acc = D
        answer += acc
        
print(answer)