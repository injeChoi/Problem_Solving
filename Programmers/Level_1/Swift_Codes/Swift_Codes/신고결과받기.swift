//
//  신고결과받기.swift
//  Swift_Codes
//
//  Created by InJe Choi on 2022/05/05.
//

import Foundation

func solution(_ id_list: [String], _ report: [String], _ k: Int) -> [Int] {
    var results = [String: Int]()
    var reportedCount = [String: Int]()
    var nominates = [String: [String]]()
    var answer = [Int]()
    let report = Set(report)
    
    for id in id_list {
        results[id] = 0
    }
    
    for info in report {
        let data = info.split(separator: " ").map { String($0) }
        let a = data[0], b = data[1]
        reportedCount[b, default: 0] += 1
        nominates[b, default: []] += [a]
    }
    
    func findPerson(_ name: String) {
        for person in nominates[name]! {
            results[person]! += 1
        }
    }
    
    for (key, value) in reportedCount {
        if value >= k {
            findPerson(key)
        }
    }
    
    for id in id_list {
        answer.append(results[id]!)
    }
    
    return answer
}

// print(solution(["muzi", "frodo", "apeach", "neo"], ["muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"], 2))
