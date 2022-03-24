//
//  하노이의탑.swift
//  Swift_Code
//
//  Created by InJe Choi on 2022/03/24.
//

import Foundation

var answer = [[Int]]()

func hanoi(_ n: Int, _ start: Int, _ mid: Int, _ end: Int) {
    if n == 1 {
        answer.append([start, end])
        return
    }
    
    hanoi(n-1, start, end, mid)
    answer.append([start, end])
    hanoi(n-1, mid, start, end)
}

func solution(_ n: Int) -> [[Int]] {
    hanoi(n, 1, 2, 3)
    return answer
}
