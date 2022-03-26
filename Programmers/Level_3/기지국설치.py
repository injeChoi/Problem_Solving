'''
https://programmers.co.kr/learn/courses/30/lessons/12979

n의 크기가 20억 이기 때문에 단순히 loop 한 번만 돌아도 터진다
따라서 수학적으로 어느 범위 안에서 몇 개의 기지국이 필요할지 계산한다

미리 주어진 n번쨰와 n+1번째 기지국이 영향을 미치는 범위를 알아두고 그 사이 범위를 알아낸다
(n번의 우측 끝자락과 n+1의 좌측 끝자락)
사이 범위 안에서 최소한의 개수로 기지국을 세워야하기 때문에
새로 지을 기지국이 영향을 끼칠 수 있는 범위 (2 * w + 1) 를 사이 범위로 부터 나눠서 
올림 처리를 하면 기지국 간 사이 범위 내에 필요한 최소 기지국 개수를 구할 수 있다
'''

from math import ceil

def solution(n, stations, w):
    answer, start, end = 0, 1, 0

    for st in stations:
        end = st - w - 1
        cnt = end - start + 1
        answer += ceil(cnt / (2 * w + 1))
        start = st + w + 1

    answer += ceil((n - start + 1) / (2 * w + 1))
    return answer

print(solution(11, [4,11], 1))