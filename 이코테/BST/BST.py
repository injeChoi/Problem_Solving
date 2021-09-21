def bst(arr, target, left, right):
    if left > right:
        return None

    mid = (left + right) // 2

    if arr[mid] == target:
        return mid

    elif arr[mid] > target:
        bst(arr, target, left, mid-1)
    
    elif arr[mid] < target:
        bst(arr, target, mid+1, right)

arr = list(map(int, input("List: ").split()))
arr.sort()
target = int(input("target: "))

result = bst(arr, target, 0, len(arr)-1)

if result == None:
    print("None")
else:
    print("Index:", result)