//
//  최댓값과최솟값.swift
//  Swift_Code
//
//  Created by InJe Choi on 2022/03/14.
//

/*
 공백 단위로 잘라서 문자열인 상태로 정렬을 하면 아스키 코드 값 기준으로 정렬을 하기 때문에
 음수인 경우 정렬이 제대로 되지 않는다
 고로, Int 형으로 캐스팅 후 정렬해서 배열의 양 끝 값을 문자열로 리턴
 */

import Foundation

func solution(_ s: String) -> String {
    var sArray = s.split(separator: " ").map{ Int($0)! }
    sArray.sort()
    
    return "\(sArray[sArray.startIndex]) \(sArray[sArray.endIndex-1])"
}

// print(solution("-1 -1"))
