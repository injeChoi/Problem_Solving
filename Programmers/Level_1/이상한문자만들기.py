def solution(s):
    answer = ''
    tmp = s.split(" ")

    for word in tmp:
        if word != '':
            for i in range(len(word)):
                if (i+1) % 2 == 1:
                    answer += word[i].upper()
                else:
                    answer += word[i].lower()
        answer += ' '
    return answer[0:-1]