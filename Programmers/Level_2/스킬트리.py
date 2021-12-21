'''
https://programmers.co.kr/learn/courses/30/lessons/49993

skill_trees에서 단어 하나 뽑아옴
단어안에 글자가 skill에 포함된다면
skill 순서에 맞는지 확인하기 위해 idx 변수로 관리

글자가 skill에 포함되는데 순서에 어긋난다면 오답처리
순서에 맞다면 idx 증가, 다음 글자가 다음 skill 순서와 비교되도록 함 
'''

def solution(skill, skill_trees):
    answer = 0
    
    for st in skill_trees:
        idx = 0
        answer += 1

        for i in range(len(st)):
            if st[i] in skill:
                if st[i] != skill[idx]:
                    answer -= 1
                    break
                else:
                    idx += 1

    return answer
