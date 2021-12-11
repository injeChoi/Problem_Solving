from collections import defaultdict

def solution(msg):
    answer = []
    string = ''
    d = defaultdict(int)

    i = 0
    while i < 26:
        d[chr(65+i)] = i + 1
        i += 1

    idx = 0
    while idx < len(msg):
        if d[string + msg[idx]] == 0:
            answer.append(d[string])
            d[string + msg[idx]] = i + 1
            i += 1
            string = ''
            continue
        else:
            string += msg[idx]

        if idx == len(msg) - 1:
            answer.append(d[string])

        idx += 1

    return answer