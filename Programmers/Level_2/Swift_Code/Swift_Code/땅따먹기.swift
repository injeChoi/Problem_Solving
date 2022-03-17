//
//  땅따먹기.swift
//  Swift_Code
//
//  Created by InJe Choi on 2022/03/17.
//

/*
 Python보다 Swift가 시간을 더 잡아먹는걸 다시 한 번 느꼈다
 시간 초과 1: O(NM)
 시간 초과 2: O(NM)
 최종 솔루션: O(N+M)
 
 전 단계에서 현재 열의 값을 제외한 값 중에서 가장 큰 값과 현재 행 현재 열의 값과 더해가면서
 마지막 행의 최댓값을 리턴
 */

import Foundation

// MARK: - 시간 초과 1
//func selectMax(_ previous: [Int], _ idx: Int) -> Int {
//    if previous.max() == previous[idx] {
//        return previous.sorted()[previous.endIndex - 2]
//    } else {
//        return previous.sorted()[previous.endIndex - 1]
//    }
//}

// MARK: - 시간 초과 2
//func solution(_ land: [[Int]]) -> Int {
//    var dp = [[Int]](repeating: [Int](repeating: 0, count: 4), count: land.count)
//    dp[0] = land[0]
//
//    for current in 1..<land.count {
//        for idx in 0...3 {
//            var previous = dp[current - 1]
//            previous.remove(at: idx)
//            dp[current][idx] = land[current][idx] + previous.max()!
//        }
//    }
//
//    return dp.last!.max()!
//}

func solution(_ land: [[Int]]) -> Int {
    var land = land
    
    for i in 1..<land.count {
        land[i][0] += max(land[i-1][1], land[i-1][2], land[i-1][3])
        land[i][1] += max(land[i-1][0], land[i-1][2], land[i-1][3])
        land[i][2] += max(land[i-1][0], land[i-1][1], land[i-1][3])
        land[i][3] += max(land[i-1][0], land[i-1][1], land[i-1][2])
    }

    return land.last!.max()!
}

// print(solution([[1,2,3,5],[5,6,7,8],[4,3,2,1]]))
