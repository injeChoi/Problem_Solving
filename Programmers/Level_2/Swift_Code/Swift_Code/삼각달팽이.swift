//
//  삼각달팽이.swift
//  Swift_Code
//
//  Created by InJe Choi on 2022/04/07.
//

/*
 https://programmers.co.kr/learn/courses/30/lessons/68645?language=swift
 
 순수 구현 문제
 
 해당 라운드에 채워야할 배열의 길이를 나타내줄 s, e 포인터와
 둘 사이에서 적절하게 시작 포인트와 끝 포인트를 지정해줄 index하나를 조합하여 해결
 */

import Foundation

func solution(_ n: Int) -> [Int] {
    var trianle = [[Int]]()
    var s = 0, e = n, num = 1, idx = 0
    
    for i in 1...n {
        trianle.append([Int](repeating: 0, count: i))
    }
    
    while s < e {
        for i in s..<e {
            trianle[i][idx] = num
            num += 1
        }
        
        for i in idx + 1..<e - idx {
            trianle[e-1][i] = num
            num += 1
        }
        
        s += 1
        e -= 1
        
        for i in stride(from: e - 1, through: s, by: -1) {
            trianle[i][i-idx] = num
            num += 1
        }
        
        idx += 1
        s += 1
    }

    return trianle.flatMap { $0 }
}

// print(solution(6))
