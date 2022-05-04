//
//  거리두기확인하기.swift
//  Swift_Code
//
//  Created by InJe Choi on 2022/05/03.
//

/*
 맨하탄 거리를 명세로 주긴 했지만 그냥 dfs로 깊이가 2 초과면 도달할 수 없는 칸으로 처리했다
 만약 중간에 X를 만나면 그냥 return시켜서 그 방향으로는 더 이상 신경 안 쓰는걸로 처리했고
 깊이 2 이하에서 "P"를 만나면 거리두기 실패이니 flag 값을 1로 만들어서 추후 모든 탐색을 바로 return 시켰다
 
 문자열에 취약한 Swift 답게 문자열 배열을 파싱하는데서 귀찮음을 다시 한 번 느꼈다
 */

import Foundation

func solution(_ places: [[String]]) -> [Int] {
    let dy = [-1, 1, 0, 0]
    let dx = [0, 0, -1, 1]
    var visited = Array(repeating: [Bool](repeating: false, count: 5), count: 5)
    var flag = 0, sy = 0, sx = 0
    var answer = [Int]()
    
    func checkRange(_ y: Int, _ x: Int) -> Bool {
        return 0..<5 ~= y && 0..<5 ~= x ? true : false
    }
    
    func dfs(_ cnt: Int, _ y: Int, _ x: Int, _ room: [[String]]) {
        if flag == 1 || cnt == 3 || room[y][x] == "X" {
            return
        }
        
        if !(y == sy && x == sx) && room[y][x] == "P" {
            flag = 1
            return
        }
        
        visited[y][x] = true
        
        for i in 0..<4 {
            let ny = y + dy[i], nx = x + dx[i]
            
            if checkRange(ny, nx) && !visited[ny][nx] {
                dfs(cnt + 1, ny, nx, room)
            }
        }
    }
    
    func search(_ room: [[String]]) {
        for i in 0..<5 {
            for j in 0..<5 {
                if room[i][j] == "P" && flag == 0 {
                    sy = i
                    sx = j
                    dfs(0, i, j, room)
                }
            }
        }
    }
    
    for place in places {
        var graph = [[String]]()
        visited = Array(repeating: [Bool](repeating: false, count: 5), count: 5)
        flag = 0
        
        for str in place {
            graph.append(str.map { String($0) })
        }
        
        search(graph)
        
        if flag == 1 {
            answer.append(0)
        } else {
            answer.append(1)
        }
    }
    
    let places = places.map { $0.map{ $0.map{ String($0) }}}
    for place in places {
        print(place)
    }
    print()
    
    return answer
}

print(solution([["POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"],
                ["POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"],
                ["PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"],
                ["OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"],
                ["PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"]]))
