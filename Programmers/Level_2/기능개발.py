import math

def solution(progresses, speeds):
    answer = []
    progresses.reverse()
    speeds.reverse()

    while progresses:
        cnt = 0
        x = progresses[len(progresses)-1]
        y = 100 - x
        z = math.ceil(y / speeds[len(progresses)-1])

        for i in range(len(progresses)):
            progresses[i] += z * speeds[i]

        for i in range(len(progresses)-1, -1, -1):
            if progresses[i] >= 100:
                cnt += 1
                progresses.pop()
            else:
                break

        answer.append(cnt)
 
    return answer
