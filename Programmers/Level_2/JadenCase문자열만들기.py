def solution(s):
    answer = ''
    lst = s.split(' ')

    for item in lst:
        answer += item.capitalize() + ' '

    if s[-1] == " ":
        return answer[:-1]
    else:
        return answer.rstrip()

solution("qa  q ")