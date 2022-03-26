//
//  보석쇼핑.swift
//  Swift_Code
//
//  Created by InJe Choi on 2022/03/26.
//

/*
 전형적인 투포인터 문제

 시작점을 s, 끝점을 e라고 하고
 s와 e 사이 범위 안의 보석들을 종류별로 카운팅
 s~e의 보석 종류 개수가 총 보석 종류 개수와 같으면
 정답 후보로 추가하고 s를 1 증가, 그리고 gems[s]를 1 감소 (gems[s]가 0이면 아예 삭제)
 같지 않으면 e를 1 증가하면서 gems[e]를 dictionary에 추가
 이때, e가 length의 범위를 초과해선 안 된다
 
 파이썬과 달리 reduce를 통해 dict.value의 합을 매번 구하면 효율성에서 시간초과가 난다
 보석 개수의 합 말고 시작점과 끝점의 차이로 개수를 세는 것이 효율적이다
 */

import Foundation

func solution(_ gems: [String]) -> [Int] {
    let length = gems.count
    var answer = [0, length]
    let gemType = Set(gems).count
    var s = 0, e = 0
    var dict = [String: Int]()
    
    func checkDict() -> Bool {
        if dict.count == gemType {
            answer = answer[1] - answer[0] <= e - s ? answer : [s, e]
            return true
        }
        return false
    }
    
    func decreaseDict(_ gem: String) {
        dict[gem, default: 0] -= 1
        if dict[gem, default: 0] <= 0 {
            dict.removeValue(forKey: gem)
        }
    }
    
    while s < length || e < length {
        if checkDict() {
            decreaseDict(gems[s])
            s += 1
        } else {
            if e < length {
                dict[gems[e], default: 0] += 1
                e += 1
            } else {
                s += 1
            }
        }
    }
    
    return [answer[0] + 1, answer[1]]
}

// print(solution(["AA", "AB", "AC", "AA", "AC"]))
