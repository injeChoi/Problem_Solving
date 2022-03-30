//
//  n^2배열자르기.swift
//  Swift_Code
//
//  Created by InJe Choi on 2022/03/30.
//

/*
 규칙 찾기가 주요
 left ~ right 범위 인덱스와 n을 나눴을 때의 몫과 나머지 중 큰 수 + 1을 해주면 답들이 나온다
 */

import Foundation

func solution(_ n: Int, _ left: Int64, _ right: Int64) -> [Int] {
    var answer = [Int]()
    let left = Int(left)
    let right = Int(right)
    
    for i in left...right {
        let q = i / n
        let r = i %  n
        let MAX = max(q, r) + 1
        answer.append(MAX)
    }
    
    return answer
}
