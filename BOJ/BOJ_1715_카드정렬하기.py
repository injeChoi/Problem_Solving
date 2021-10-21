from queue import PriorityQueue

q = PriorityQueue()
N = int(input())
ans = 0

for i in range(N):
    num = int(input())
    q.put(num)

if q.qsize() == 1:
    print(0)
else: 
    while q.qsize() != 1:
        a = q.get()
        b = q.get()
        ans += a + b
        q.put(a + b)
    print(ans)
