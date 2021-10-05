val = list(input().split('-'))
nums = []
ans = 0

for v in val:
    total = 0
    tmp = v.split('+')
    for t in tmp:
        total += int(t)
    nums.append(total)

ans = nums[0]
for i in range(1, len(nums)):
    ans -= nums[i]

print(ans)