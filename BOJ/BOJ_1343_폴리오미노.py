board = input()
answer = ""
cnt = 0

for i in range(len(board)):
    if board[i] == 'X':
        cnt += 1
    else:
        if cnt % 2 == 1:
            print(-1)
            exit(0)

if cnt % 2 == 1:
    print(-1)
    exit(0)

cnt = 0
for i in range(len(board)):
    if board[i] == '.' or i == len(board)-1:
        if board[i] == 'X':
            cnt += 1
        answer += "AAAA" * (cnt // 4)
        cnt %= 4
        if cnt > 1:
            answer += "BB"
        if board[i] == '.':
            answer += '.'
        cnt = 0
    else:
        cnt += 1

print(answer)