//
//  가장긴팰린드롬.swift
//  Swift_Code
//
//  Created by InJe Choi on 2022/03/25.
//

/*
 파이썬과 동일한 로직으로 수행 시 현재 코드보다 3배 가량 오래 걸림
 하지만 현재 코드도 효율성 2개 중 1개에서 걸림
 Swift로 통과하려면 로직 전체를 수정해야할 필요가 있지만
 파이썬 로직이 틀린 것은 아니므로 여기까지
 */

import Foundation

extension String {
    var isPalindrome: Bool {
        self == String(self.reversed())
    }
}

func solution(_ s:String) -> Int {
    var answer = 1
    
    for i in 0..<s.count {
        for j in stride(from: s.count - i, to: answer, by: -1) {
            let startIndex = s.index(s.startIndex, offsetBy: i)
            let endIndex = s.index(s.startIndex, offsetBy: i + j - 1)
            let substring = String(s[startIndex...endIndex])
            if substring.isPalindrome {
                answer = max(answer, substring.count)
            }
        }
    }
    
    return answer
}

// print(solution("abcdcba"))
