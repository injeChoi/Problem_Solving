//
//  가장큰수.swift
//  Swift_Code
//
//  Created by InJe Choi on 2022/04/25.
//

/*
 원소들을 최소 3자리 숫자로 맞춘다, ex) 3 -> 333
 동일한 패턴의 문자열들의 대소를 비교하기 위함, ex) 3, 30 -> 333, 303030, 고로 3을 먼저 사용
 */

import Foundation

func solution(_ numbers:[Int]) -> String {
    var nums = numbers.map { String($0) }

    nums.sort {
        let left = String(repeating: String($0), count: 3)
        let right = String(repeating: String($1), count: 3)
        return left > right
    }
    
    if nums[0] == "0" {
        return "0"
    }
    return nums.joined()
}

// print(solution([6, 2, 10]))
