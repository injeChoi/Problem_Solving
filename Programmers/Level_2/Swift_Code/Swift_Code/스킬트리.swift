//
//  스킬트리.swift
//  Swift_Code
//
//  Created by InJe Choi on 2022/03/24.
//

/*
 시간복잡도에서 우위: solution1
 Swift 스러움: solution2
 */

import Foundation

func solution1(_ skill: String, _ skill_trees: [String]) -> Int {
    var answer = 0
    let s = Array(skill)

    for skill_tree in skill_trees {
        let st = Array(skill_tree)
        var idx = 0
        answer += 1

        for i in 0..<st.count {
            if s.contains(st[i]) {
                if st[i] != s[idx] {
                    answer -= 1
                    break
                } else {
                    idx += 1
                }
            }
        }
    }

    return answer
}

func findStartWith(_ skill: String, _ skillTree: String) -> Bool {
    let skillInSkillTree = skillTree.filter { skill.contains($0) }
    return skill.starts(with: skillInSkillTree)
}

func solution2(_ skill:String, _ skill_trees:[String]) -> Int {
    skill_trees
        .map { findStartWith(skill, $0) }
        .filter { $0 }
        .count
}

// print(solution2("CBD", ["BACDE", "CBADF", "AECB", "BDA"]))

