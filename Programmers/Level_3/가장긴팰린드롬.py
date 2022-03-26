'''
https://programmers.co.kr/learn/courses/30/lessons/12904

의외로 2중 for문으로 풀리는 문제
시간 복잡도 고려를 잘못해서 2중 for문으로 풀면 안 되는줄 알았다
2500!이 아니라 2500+2499+2498+...1 까지로 NM에 가까운 문제였다
고로 문자열을 i~j까지 슬라이싱 해서 해당 부분 문자열이 팰린드롬인지 매번 체크해도 된다
'''

def solution(s):
    answer = 1
    
    def palindrome(substring):
        if substring == substring[::-1]:
            return True
        
    for i in range(len(s)):
        for j in range(i+1, len(s)):
            if palindrome(s[i:j+1]):
                answer = max(answer, len(s[i:j+1]))
    
    return answer

print(solution("abcdcba"))