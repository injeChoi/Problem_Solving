//
//  스타수열.swift
//  Swift_Code
//
//  Created by InJe Choi on 2022/03/30.
//

/*
 https://programmers.co.kr/learn/courses/30/lessons/70130?language=swift
 
 배열이 크든 작든 Array Slicing 후 contains 메소드를 통해 조사하는 방식은 시간 효율면에서 좋지 않다
 Array Slice는 결국 원본 배열의 복제본을 하나 만들고 참조하고 있는 것이기 때문에
 이 작업 자체가 무겁다고 볼 수 있다
 여기서 또 contains 메소드를 통해 O(N)의 시간 복잡도로 조사를 하기 때문에 시간 효율면에서 매우 안 좋다
 
 고로, 배열의 특정 범위에서만 조회하고 싶어도 Subsequence를 따로 만들지 말고
 웬만해선 원본 배열에서 특정 범위를 반복문을 통해 순회하면서 값을 직접 비교하는 것이 더욱 빠르다
 
 ex)
 지양해야 하는 방식: arr[idx...idx+10].contains($0)
 */

import Foundation

func solution(_ a: [Int]) -> Int {
    if a.count < 2 {
        return 0
    }
    
    var answer = 0
    var counter = [Int: Int]()
    a.forEach { counter[$0, default: 0] += 1 }
    
    counter.forEach {
        if $1 * 2 < answer {
            return
        }
        var idx = 0, length = 0
        while idx < a.count - 1 {
            if (a[idx] != $0 && a[idx+1] != $0) || a[idx] == a[idx+1] {
                idx += 1
                continue
            }
            idx += 2
            length += 2
        }
        answer = max(answer, length)
    }
    
    return answer
}

// print(solution([5,2,3,3,5,3]))
