//
//  카펫.swift
//  Swift_Code
//
//  Created by InJe Choi on 2022/04/14.
//

/*
 1. brown + yellow 값의 약수를 구함
 2. 약수의 개수가 짝수이면 약수 쌍 중 (약수1의 값 - 2) * (약수2의 값 - 2) 의 값이 yellow랑 같으면 그게 정답
 3. 약수의 개수가 홀수이면 약수 중 단일 값인 값이 정답
 */

import Foundation

func solution(_ brown: Int, _ yellow: Int) -> [Int] {
    let total = brown + yellow
    var nums = [Int]()
    
    for i in 1...total {
        if total % i == 0 {
            nums += [i]
        }
    }
    
    if nums.count % 2 == 0 {
        for i in 0..<nums.count {
            if (nums[i] - 2) * (nums[nums.count - 1 - i] - 2) == yellow {
                return [nums[nums.count - 1 - i], nums[i]]
            }
        }
    }
    return [nums[nums.count / 2], nums[nums.count / 2]]
}

// print(solution(18, 6))
