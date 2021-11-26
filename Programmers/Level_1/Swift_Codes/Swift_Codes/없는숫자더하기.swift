//
//  없는숫자더하기.swift
//  Swift_Codes
//
//  Created by InJe Choi on 2021/11/26.
//

import Foundation

func solution(_ numbers:[Int]) -> Int {

    let arr = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    let tmp = arr.filter{!numbers.contains($0)}
    let answer = tmp.reduce(0, +)

    return answer
}
