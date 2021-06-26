#include <bits/stdc++.h>
using namespace std;

int A, B, C;
bool visited[201][201][201];

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

vector<int> BFS() {
    vector<int> result;
    queue<tuple<int, int, int> > q;
    q.push({0, 0, C});

    while (!q.empty()) {
        int x, y, z;
        tie(x, y, z) = q.front();
        q.pop();

        if (visited[x][y][z]) continue;
        visited[x][y][z] = true;

        if (x == 0) result.push_back(z);

        // A to B
        if (x + y > B) q.push({x + y - B, B, z});
        else q.push({0, x + y, z});

        // A to C
        if (x + z > C) q.push({x + z - C, y, C});
        else q.push({0, y, x + z});

        // B to A
        if (y + x > A) q.push({A, y + x - A, z});
        else q.push({y + x, 0, z});

        // B to C
        if (y + z > C) q.push({x, y + z - C, C});
        else q.push({x, 0, y + z});

        // C to A
        if (z + x > A) q.push({A, y, z + x - A});
        else q.push({z + x, y, 0});

        // C to B
        if (z + y > B) q.push({x, B, z + y - B});
        else q.push({x, z + y, 0});
    }
    return result;
}

int main(int argc, char const *argv[]) {
    init();
    cin >> A >> B >> C;

    vector<int> result = BFS();
    sort(result.begin(), result.end());

    for (int i = 0; i < result.size(); i++) 
        cout << result[i] << " ";
    cout << endl;

    return 0;
}