def solution(n, k):
    answer = -1

    def toNary():
        nonlocal n, k
        s = ""

        while n > 0:
            s += str(n % k)
            n //= k

        return s[::-1]

    convertedNumber = toNary()

    lst = convertedNumber.split("0")

    



    return answer

solution(10, 3)