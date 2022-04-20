//
//  예상대진표.swift
//  Swift_Code
//
//  Created by InJe Choi on 2022/04/19.
//

/*
 a와 b를 반으로 나눠서 올림처리를 하면 다음 라운드 때 자신의 번호를 알 수 있다
 만약 a가 짝수일 때 b가 a보다 작은 가장 큰 홀수 이면 둘이 맞붙는 상황이고
 a가 홀수일 때 b가 a보다 큰 가장 작은 짝수이면 둘이 맞붙는 상황이다
 */

import Foundation

func solution(_ n: Int, _ a: Int, _ b: Int) -> Int {
    var answer = 1, a = a, b = b
    
    while true {
        if (a % 2 == 0 && a - 1 == b) || (a % 2 == 1 && a + 1 == b) {
            break
        }
        answer += 1
        a = Int(ceil(Double(a) / 2))
        b = Int(ceil(Double(b) / 2))
    }
    
    return answer
}

// print(solution(8, 4, 5))

