//
//  숫자게임.swift
//  Swift_Code
//
//  Created by InJe Choi on 2022/03/25.
//

import Foundation

var aPointer = 0

func compareAB(_ a: Int, _ b: Int) -> Bool {
    if a < b {
        aPointer += 1
        return true
    }
    return false
}

func solution(_ a: [Int], _ b: [Int]) -> Int {
    let A = a.sorted()
    let B = b.sorted()
    
    return B.filter { compareAB(A[aPointer], $0) }.count
}

// print(solution([1,2,4,12,16],[0,1,3,11,17]))
