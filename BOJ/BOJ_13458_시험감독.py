N = int(input())
classes = list(map(int, input().split()))
B, C = map(int, input().split())
total = 0

for room in classes:
    room -= B
    total += 1

    if room <= 0:
        continue
    
    if room % C == 0:
        total += room // C
    else:
        total += room // C + 1

print(total)