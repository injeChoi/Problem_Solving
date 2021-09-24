def solution(s, n):
    answer = ""
    for i in s:
        if i != ' ':
            if 65 <= ord(i) <= 90: 
                if ord(i) + n <= 90:
                    answer += chr(ord(i) + n)
                else:
                    answer += chr(ord(i) + n - 90 + 64)
            else:
                if ord(i) + n <= 122:
                    answer += chr(ord(i) + n)
                else:
                    answer += chr(ord(i) + n - 122 + 96)
        else:
            answer += ' '

    return answer
