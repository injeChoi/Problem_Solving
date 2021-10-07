N, M = map(int, input().split())
nums = ['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine']
alphabets = []
answer = []

for i in range(N, M+1):
    s = str(i)
    tmp = ''
    for j in range(len(s)):
        tmp += ' ' + nums[int(s[j])]
    alphabets.append(tmp)
alphabets.sort()

for num in alphabets:
    digit = ''
    tmp = num[1:]
    lst = tmp.split()
    for l in lst:
        digit += str(nums.index(l))
    answer.append(int(digit))

for i, num in enumerate(answer):
    if i >= 10 and i % 10 == 0:
        print()
    print(num, end=' ')

