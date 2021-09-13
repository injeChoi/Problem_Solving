//
//  소수만들기.swift
//  Swift_Codes
//
//  Created by InJe Choi on 2021/09/13.
//

import Foundation

let MAX = 3001
var isPrime = [Bool](repeating: true, count: MAX)
var makeSum = [Int](repeating: 0, count: 3)
var answer = 0

func sosu() {
    isPrime[0...1] = [false, false]
    for i in stride(from: 2, to: Int(sqrt(Double(MAX))), by: 1) {
        if isPrime[i] == false {
            continue
        }
        for j in stride(from: i+i, to: MAX, by: i) {
            isPrime[j] = false
        }
    }
}

func DFS(_ tmpNums:[Int], _ idx:Int, _ cnt:Int) {
    if cnt == 3 {
        var sum = 0
        sum += makeSum.reduce(0, +)
        if isPrime[sum] == true {
            answer += 1
        }
        return
    }
    for i in stride(from: idx, to: tmpNums.count, by: 1) {
        makeSum[cnt] = tmpNums[i]
        DFS(tmpNums, i+1, cnt+1)
    }
}

func solution(_ nums:[Int]) -> Int {
    sosu()
    DFS(nums, 0, 0)
    return answer
}
