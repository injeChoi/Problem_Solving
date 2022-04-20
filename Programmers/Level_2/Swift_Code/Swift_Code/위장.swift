//
//  위장.swift
//  Swift_Code
//
//  Created by InJe Choi on 2022/04/19.
//

/*
 https://programmers.co.kr/learn/courses/30/lessons/42578

 Hash보단 경우의 수 문제(?)
 특정 종류의 옷을 안 입는 경우 때문에 특정 종류 옷의 개수 + 1
 모든 종류의 옷 개수를 곱하면 옷을 입는 모든 경우의 수가 나온다.
 옷을 안 입는 경우는 없으니 최종 값에서 -1
 고로, (item1 + 1) * (item2 + 1) * ... * (itemN + 1) - 1
 */

import Foundation

func solution(_ clothes: [[String]]) -> Int {
    var answer = 1
    var dict = [String: Int]()
    
    for cloth in clothes {
        dict[cloth[1], default: 0] += 1
    }
    
    for cloth in dict.values {
        answer *= cloth + 1
    }
    
    return answer - 1
}
