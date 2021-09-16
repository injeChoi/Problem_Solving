change = int(input("거스름 돈: "))
five_hundred = one_hundred = fifty = ten = total = 0

while change > 0:
    if change // 500 > 0:
        five_hundred += 1
        change -= 500
    elif change // 100 > 0:
        one_hundred += 1
        change -= 100
    elif change // 50 > 0:
        fifty += 1
        change -= 50
    elif change // 10 > 0:
        ten += 1
        change -= 10

print(five_hundred, one_hundred, fifty, ten)
