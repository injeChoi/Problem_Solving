//
//  main.swift
//  Swift_Code
//
//  Created by InJe Choi on 2022/03/22.
//

import Foundation

func solution(_ n: Int) -> Int {
    var memo = [1, 2]
    
    if n == 1 {
        return 1
    }
    
    for i in 2...n {
        memo.append((memo[i-1] + memo[i-2]) % 1234567)
    }
    
    return memo[n-1]
}

print(solution(4))
