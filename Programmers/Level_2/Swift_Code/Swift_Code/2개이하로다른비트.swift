//
//  2개이하로다른비트.swift
//  Swift_Code
//
//  Created by InJe Choi on 2022/04/12.
//

/*
 https://programmers.co.kr/learn/courses/30/lessons/77885

 비트마스킹으로 풀다가 시간초과 발생
 - 비트마스킹으로 나온 바이너리 문자열에서 count 함수를 쓰니 최대 10^15의 시간이 걸림

 n이 짝수일 경우 이진 비트의 마지막 자리가 항상 0이니 이를 1로 수정만 해주면 n보다 큰 가장 작은 수가 된다.
 n이 홀수일 경우 위의 치트키를 사용 못하니 다른 로직을 떠올려야 한다.
 이진비트 문자열의 가장 오른쪽에서부터 0을 찾는다
 해당 자리를 1로 바꾸고 해당 자리의 오른쪽 1을 0으로 바꾼다
 7과 같이 0b111로 0이 없는 값이 나오는 경우가 있으니
 이럴 때를 대비하여 이진법으로 바꾼 숫자 제일 왼쪽에 임의로 0을 추가한다
 이렇게 하면 총 비트 2자리를 바꾼 숫자 중 n 보다 큰 가장 작은 수가 된다.
 */

import Foundation

func solution(_ numbers: [Int64]) -> [Int64] {
    
    func findSmallest(_ num: Int64) -> Int64 {
        if num % 2 == 0 {
            return num + 1
        }
        
        var binNum = ["0"] + Array(String(num, radix: 2)).map { String($0) }
        var idx = binNum.count - 1
        
        for (i, item) in binNum.reversed().enumerated() {
            if item == "0" {
                idx -= i
                break
            }
        }
        
        binNum[idx] = "1"
        binNum[idx+1] = "0"
        
        return Int64(binNum.joined(), radix: 2)!
    }

    return numbers.map { findSmallest($0) }
}

// print(solution([2, 7]))
