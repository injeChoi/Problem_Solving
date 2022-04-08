//
//  영어끝말잇기.swift
//  Swift_Code
//
//  Created by InJe Choi on 2022/04/07.
//

/*
 주어진 조건만 잘 따라서 풀면 쉬운 문제
 몇 번째 사람인지와 몇 번째 차례인지 구하는 것만 살짝 신경쓰면 된다
 */

import Foundation

func solution(_ n: Int, _ words: [String]) -> [Int] {
    var answer = [0, 0]
    var s = Set<String>()
    
    for (idx, word) in words.enumerated() {
        if !s.insert(word).0 || word.count == 1 || (idx > 0 && words[idx-1].last != word.first) {
            let personNumber = (idx + 1) % n == 0 ? n : (idx + 1) % n
            answer = [personNumber, Int(ceil(Double(idx+1) / Double(n)))]
            break
        }
    }
    return answer
}

// print(solution(2, ["hello", "one", "even", "never", "now", "world", "draw"]))
