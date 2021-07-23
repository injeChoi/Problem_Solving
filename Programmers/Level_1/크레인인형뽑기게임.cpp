#include <bits/stdc++.h>
using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> st;
    for (int i = 0; i < moves.size(); i++) {
        int pick = moves[i]-1;

        for (int i = 0; i < board.size(); i++) {
            if (board[i][pick] == 0) {
                continue;
            }
            else {
                if (!st.empty()) {
                    if (st.top() == board[i][pick]) { 
                        answer += 2;
                        st.pop();
                    }
                    else {
                        st.push(board[i][pick]);
                    }
                }
                else {
                    st.push(board[i][pick]);
                }
                board[i][pick] = 0;
                break;
            }
        }
    }
    return answer;
}