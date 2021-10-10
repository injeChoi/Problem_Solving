S = input()
lst = []
for i in range(1, len(S)):
    front = S[:i][::-1]
    for j in range(i+1, len(S)):
        mid = S[i:j][::-1]
        rear = S[j:][::-1]
        lst.append(front+mid+rear)

lst.sort()
print(lst[0])