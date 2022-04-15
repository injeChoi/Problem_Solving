//
//  H-Index.swift
//  Swift_Code
//
//  Created by InJe Choi on 2022/04/15.
//

/*
 문제 명세가 살짝 헷갈렸던 문제
 배열 정렬 후 특정 숫자 기준 이상, 이하인 인용 값을 따로 기록 후
 이상 값이 특정 숫자보다 크거나 같고, 이하인 값이 특정 숫자보다 작거나 같다면
 H-Index 후보
 그중 가장 큰 값을 리턴
 
 정렬을 내림차순으로 했으면 MAX 값을 일일이 비교할 필요가 없을듯
 */

import Foundation

func solution(_ citations: [Int]) -> Int {
    var MAX = 0, citations = citations
    citations.sort()
    
    for h in 0..<citations[citations.count - 1] {
        var citated = 0, rest = 0
        for c in citations {
            if c >= h {
                citated += 1
            } else {
                rest += 1
            }
        }
        if citated >= h && rest <= h {
            MAX = h
        }
    }
    
    return MAX
}
