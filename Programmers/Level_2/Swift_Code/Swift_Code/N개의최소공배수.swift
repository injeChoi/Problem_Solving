//
//  N개의최소공배수.swift
//  Swift_Code
//
//  Created by InJe Choi on 2022/03/09.
//

import Foundation

func gcd(_ a: Int, _ b: Int) -> Int {
    if b == 0 {
        return a
    } else {
        return gcd(b, a % b)
    }
}

func lcm(_ a: Int, _ b: Int) -> Int {
    return a * b / gcd(a, b)
}

func solution(_ arr:[Int]) -> Int {
    var answer = 1

    arr.forEach {
        answer = lcm(answer, $0)
    }

    return answer
}

// print(solution([1,2,3]))
