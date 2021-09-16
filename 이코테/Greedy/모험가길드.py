number = int(input("모험가 수: "))
gongpo = list(map(int, input("공포도: ").split(" ")))
gongpo.sort()

group = result = 0

for item in gongpo:
    group += 1
    if group >= item:
        result += 1
        group = 0

print(result)