def solution(strings, n):
    answer = []
    idxstring = []

    for word in strings:
        idxstring.append((word[n], word))

    idxstring.sort()

    for idx, word in idxstring:
        answer.append(word)
    print(answer)
    return answer

# lambda 풀이 
def solution(words, n):
    return sorted(sorted(words), key=lambda x: x[n])

solution(["sun", "bed", "car"], 1)