//
//  다음큰숫자.swift
//  Swift_Code
//
//  Created by InJe Choi on 2022/03/18.
//

/*
 10진수를 n진수로 바꾸는 방법: String(num, radix: n)
 n진수를 10진수로 바꾸는 방법: Int(num, radix: 10)!, 이때 num은 문자열
 Swift에는 문자열 안에 특정 element의 개수를 세주는 메소드가 없기 때문에 filter로 직접 카운팅
 */

import Foundation

func solution(_ n: Int) -> Int {
    let cnt = String(n, radix: 2).filter { $0 == "1" }.count
    
    for i in n+1...1000000 {
        let converted = String(i, radix: 2).filter { $0 == "1" }.count
        if cnt == converted {
            return i
        }
    }
    
    return 0
}

// print(solution(15))
