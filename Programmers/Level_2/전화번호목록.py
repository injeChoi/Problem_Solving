def solution(phone_book):
    phone_book.sort()
    
    for first, second in zip(phone_book, phone_book[1:]):
        if second.startswith(first):
            return False
    return True

solution(["119", "97674223", "1195524421"])