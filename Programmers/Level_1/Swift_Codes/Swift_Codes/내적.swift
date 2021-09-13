//
//  내적.swift
//  Swift_Codes
//
//  Created by InJe Choi on 2021/09/11.
//

import Foundation

func solution(_ a:[Int], _ b:[Int]) -> Int {
    var answer = 0
    for i in 0..<a.count {
        answer += a[i] * b[i]
    }
    return answer
}
print("hello")
