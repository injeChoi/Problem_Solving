//
//  단어변환.swift
//  Swift_Code
//
//  Created by InJe Choi on 2022/05/25.
//

/*
 https://programmers.co.kr/learn/courses/30/lessons/43163?language=swift
 
 */

import Foundation

func solution(_ begin:String, _ target:String, _ words:[String]) -> Int {
    var answer = Int.max
    var visited = [Bool](repeating: false, count: words.count)
    
    if !words.contains(target) {
        return 0
    }
    
    func diffCount(_ a: String, _ b: String) -> Int {
        return zip(a, b).filter { $0.0 != $0.1 }.count
    }
    
    func dfs(_ cnt: Int, _ tmp: String) {
        if cnt >= answer {
            return
        }
        
        if tmp == target {
            answer = cnt
            return
        }
        
        for i in 0..<words.count {
            if !visited[i] && diffCount(tmp, words[i]) < 2 {
                visited[i] = true
                dfs(cnt + 1, words[i])
                visited[i] = false
            }
        }
    }
    
    dfs(0, begin)
    return answer
}

// print(solution("hit", "cog", ["hot", "dot", "dog", "lot", "log", "cog"]))
