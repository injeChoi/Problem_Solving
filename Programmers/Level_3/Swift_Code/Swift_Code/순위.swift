//
//  순위.swift
//  Swift_Code
//
//  Created by InJe Choi on 2022/03/24.
//

import Foundation

func solution(_ n: Int, _ results: [[Int]]) -> Int {
    var answer = 0
    var weakerThan = [Int: Set<Int>](), strongerThan = [Int: Set<Int>]()
    
    for result in results {
        let winner = result[0], loser = result[1]
        weakerThan[winner, default: Set<Int>()].insert(loser)
        strongerThan[loser, default: Set<Int>()].insert(winner)
    }

    for person in 0...n {
        if let strongPeople = strongerThan[person],
            let people = weakerThan[person] {
            for strongPerson in strongPeople {
                weakerThan[strongPerson] = weakerThan[strongPerson]?.union(people)
            }
        }
        
        if let weakPeople = weakerThan[person],
            let people = strongerThan[person] {
            for weakPerson in weakPeople {
                strongerThan[weakPerson] = strongerThan[weakPerson]?.union(people)
            }
        }
    }
    
    for i in 1...n {
        let loser = weakerThan[i, default: Set<Int>()].count
        let winner = strongerThan[i, default: Set<Int>()].count
        
        if loser + winner == n - 1 {
            answer += 1
        }
    }
    
    return answer
}

// print(solution(5, [[4, 3], [4, 2], [3, 2], [1, 2], [2, 5]]))
