//
//  단어변환.swift
//  Swift_Code
//
//  Created by InJe Choi on 2022/05/25.
//

/*
 https://programmers.co.kr/learn/courses/30/lessons/43163?language=swift
 
 방문처리 배열 만든 후, words배열 안에 원소들이랑 한 글자 씩 바껴 간 begin(tmp)랑 비교
 방문하지 않은 원소이고 차이가 2 미만이면 그 단어로 바껴보고 다음 단어 탐색
 이런식으로 dfs 쭉 진행하다가 begin(tmp) == target인 경우 바뀐 횟수 답으로 처리
 이때, 바뀐 횟수가 답 보다 크면 return 
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
