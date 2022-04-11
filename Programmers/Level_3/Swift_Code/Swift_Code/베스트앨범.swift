//
//  영어끝말잇기.swift
//  Swift_Code
//
//  Created by InJe Choi on 2022/04/08.
//

/*
 https://programmers.co.kr/learn/courses/30/lessons/42579

 자료구조를 어떻게 나눠서 쓸지 고민하는데 시간이 많이 든 문제
 (dictionary의 key와 value를 어떻게 설정할지,
 정렬이 꼭 필요하니 리스트가 필요한데 value를 list형으로 만드는게 맞을지 등)

 genres와 plays의 길이가 10,000 이하로 작으니 2중 반복을 하더라도
 최악의 경우에도 시간초과가 나지 않을것이니까 장르별로 값을 뽑아서 배열에 넣는 방식으로 풀이
 */

import Foundation

func solution(_ genres: [String], _ plays: [Int]) -> [Int] {
    var dict = [String: Int]()
    var p1 = 0
    var answer = [Int]()
    
    for i in 0..<genres.count {
        dict[genres[i], default: 0] += plays[i]
    }
    
    let sortedDict = dict.sorted { $0.1 > $1.1 }
    
    for item in sortedDict {
        var arr = [(Int, Int)]()
        
        for i in 0..<genres.count {
            if genres[i] == item.key {
                arr.append((plays[i], i))
            }
        }
        
        arr.sort {
            if $0.0 == $1.0 {
                return $0.1 > $1.1
            }
            return $0.0 < $1.0
        }
        
        p1 = arr.popLast()?.1 ?? -1
        answer += [p1]
        if let p2 = arr.popLast()?.1 {
            answer += [p2]
        }
    }
    
    return answer
}

// print(solution(["classic", "pop", "classic", "classic", "pop"], [500, 600, 150, 800, 2500]))

