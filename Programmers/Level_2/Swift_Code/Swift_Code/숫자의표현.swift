//
//  숫자의표현.swift
//  Swift_Code
//
//  Created by InJe Choi on 2022/03/15.
//

/*
 Swift는 for문의 iterator가 default로 상수이기 때문에
 for문 안에서 iterator 값을 변경해서 쓰려면 변수로 명시해줘야 한다.
 하지만 while문 안에서의 i += 1 연산은 for문의 i 변수에게 영향을 주지 못하고
 for문의 i 변수를 복제해서 사용하는 새로운 i를 가져다 쓰는 느낌이다.
 즉, for문의 i는 while 문의 i += 1 연산과는 상관없이 1...n 까지 1씩 증가하고
 while 문의 i는 for문의 i 값을 복제하여 초기값을 갖고 1씩 증가하지만 for문의 i에게는 영향을 주지 않는다.
 */

import Foundation

func solution(_ n: Int) -> Int {
    var answer = 0
    
    for var i in 1...n {
        var target = 0
        
        while target < n {
            target += i
            i += 1
        }
        
        if target == n {
            answer += 1
        }
    }
    
    return answer
}

// print(solution(15))
