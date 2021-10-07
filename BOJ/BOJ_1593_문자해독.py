g, l = map(int, input().split())
W, S = input(), input()
answer = 0
W_alphabet = [0] * 52 # 대문자 소문자 순서 
S_alphabet = [0] * 52

for i in range(g):
    if 'A' <= W[i] <= 'Z':
        W_alphabet[ord(W[i])-ord('A')] += 1
    elif 'a' <= W[i] <= 'z':
        W_alphabet[ord(W[i])-ord('a')+26] += 1

start = length = 0
for i in range(l):
    if 'A' <= S[i] <= 'Z':
        S_alphabet[ord(S[i])-ord('A')] += 1
    elif 'a' <= S[i] <= 'z':
        S_alphabet[ord(S[i])-ord('a')+26] += 1

    length += 1

    # W 길이와 부분 S의 길이가 같아졌을 때
    if length == g:
        # 리스트가 동일하다면 => 문자 조합이 동일 
        if W_alphabet == S_alphabet:
            answer += 1
        # 부분 문자열 슬라이딩, S 리스트에서 부분 문자열 첫번째 문자의 개수 -1 
        if 'A' <= S[start] <= 'Z':
            S_alphabet[ord(S[start])-ord('A')] -= 1
        elif 'a' <= S[start] <= 'z':
            S_alphabet[ord(S[start])-ord('a')+26] -= 1
        # 부분 문자열 개수 -1, 부분 문자열 첫번째 문자 인덱스 +1 
        length -= 1
        start += 1

print(answer)
