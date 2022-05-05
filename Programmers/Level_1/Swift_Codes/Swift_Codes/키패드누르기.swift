//
//  키패드누르기.swift
//  Swift_Codes
//
//  Created by InJe Choi on 2022/05/04.
//

/*
 https://programmers.co.kr/learn/courses/30/lessons/67256
 
 키패드 위치를 저장하는 딕셔너리 만들고
 새로 눌러야 하는 번호의 위치가 1번 열에 있으면
 현재 좌, 우 손가락 위치 부터 새로 눌러야하는 번호의 위치까지의 맨해튼 거리를 구한 후
 상황에 맞는 값 추가
 */

import Foundation

func solution(_ numbers: [Int], _ hand: String) -> String {
    var answer = ""
    let numbers = numbers.map { String($0) }
    var left = "*", right = "#"
    let leftSide = ["1", "4", "7"], rightSide = ["3", "6", "9"]
    let keypad: [String: (Int, Int)] = ["1": (0, 0), "2": (0, 1), "3": (0, 2),
                                        "4": (1, 0), "5": (1, 1), "6": (1, 2),
                                        "7": (2, 0), "8": (2, 1), "9": (2, 2),
                                        "*": (3, 0), "0": (3, 1), "#": (3, 2)]
    
    func checkDistance(_ num: String) -> String? {
        guard let y = keypad[num]?.0, let x = keypad[num]?.1,
              let ly = keypad[left]?.0, let lx = keypad[left]?.1,
              let ry = keypad[right]?.0, let rx = keypad[right]?.1 else {
            return nil
        }
        
        let leftDistance = abs(y - ly) + abs(x - lx)
        let rightDistance = abs(y - ry) + abs(x - rx)
        
        if leftDistance < rightDistance {
            return "L"
        } else if rightDistance < leftDistance {
            return "R"
        } else {
            return hand == "left" ? "L" : "R"
        }
    }
    
    for number in numbers {
        if leftSide.contains(number) {
            answer += "L"
            left = number
        } else if rightSide.contains(number) {
            answer += "R"
            right = number
        } else {
            if let side = checkDistance(number) {
                answer += side
                if side == "L" {
                    left = number
                } else {
                    right = number
                }
            }
        }
    }
    
    return answer
}
