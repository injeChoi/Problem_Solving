//
//  이진변환반복하기.swift
//  Swift_Code
//
//  Created by InJe Choi on 2022/04/01.
//

/*
 1. x에서 0의 개수 세기
 2. x에서 0제거
 3. x의 길이를 2진법으로 변환
 4. 변환 횟수 1증가
 */

import Foundation

func solution(_ s: String) -> [Int] {
    var x = s
    var convertCount = 0
    var zeroCount = 0
    
    while x != "1" {
        zeroCount += x.filter { $0 == "0" }.count
        x = String(x.filter { $0 == "1" }.count, radix: 2)
        convertCount += 1
    }
    
    return [convertCount, zeroCount]
}

// print(solution("01110"))
