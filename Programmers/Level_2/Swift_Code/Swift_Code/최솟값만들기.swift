//
//  최솟값만들기.swift
//  Swift_Code
//
//  Created by InJe Choi on 2022/03/14.
//

/*
 A와 B 배열을 정렬해야 하는데 작은 수 * 큰 수를 해야 최종 값이 최솟값이 되므로 정렬을 다르게 했다
 
 풀이1, 풀이2, 풀이3 순서로 아이디어를 떠올려서 풀었다
 풀이1은 가장 기본적인 풀이, indices를 사용해서 안전한 범위 내에서만 iteration을 보장했다
 풀이2는 python에서는 zip함수가 있는데 swift에는 없나? 싶어서 검색해보니 swift에도 있길래 써봤다
 풀이3은 zip이 있다면 고차함수로도 풀 수 있지 않을까 싶어서 해보니 잘 됐다
 */

import Foundation

// MARK: - 풀이 1
func solution1(_ A: [Int], _ B: [Int]) -> Int {
    var ans = 0
    let A = A.sorted()
    let B = B.sorted(by: >)
    
    for idx in A.indices {
        ans += A[idx] * B[idx]
    }

    return ans
}

// MARK: - 풀이 2
func solution2(_ A: [Int], _ B: [Int]) -> Int {
    var ans = 0
    let A = A.sorted()
    let B = B.sorted(by: >)

    for (a, b) in zip(A, B) {
        ans += a * b
    }

    return ans
}

// MARK: - 풀이 3
func solution3(_ A: [Int], _ B: [Int]) -> Int {
    return zip(A.sorted(), B.sorted(by: >)).map{ $0 * $1 }.reduce(0, +)
}

//print(solution1([1, 2], [3, 4]))
//print(solution2([1, 2], [3, 4]))
//print(solution3([1, 2], [3, 4]))

