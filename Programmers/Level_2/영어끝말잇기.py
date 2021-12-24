'''
https://programmers.co.kr/learn/courses/30/lessons/12981

문제 명세대로 이미 있는 단어 또는 끝말 잇기가 안 된 단어를 거른다.
해당 단어의 순번을 기준으로 게임 참가인원으로 나머지 연산을 하면 몇 번째 사람이 틀렸는지 알 수 있고
나누기 연산을 통해 몇 번째 라운드인지 알 수 있다.
'''

from math import ceil

def solution(n, words):
    answer = [0, 0]
    lst = []

    for idx, word in enumerate(words):
        if word in lst or (len(lst) > 0 and word[0] != lst[-1][-1]):
            if (idx + 1) % n == 0:
                answer[0] = n
            else:
                answer[0] = (idx + 1) % n
                
            answer[1] = ceil((idx + 1) / n)
            break
        else:
            lst.append(word)

    return answer
