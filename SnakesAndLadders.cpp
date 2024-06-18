#include<bits/stdc++.h>
using namespace std;

vector<int> find_coordinates(int curr, int n) {
    int r = n - (curr - 1) / n - 1;
    int c = (curr - 1) % n;
    if (r % 2 == n % 2) {
        c = n - 1 - c;
    }
    return {r, c};
}

int snakesAndLadders(vector<vector<int>>& board) {
    int n = board.size();
    int steps = 0;
    queue<int> q;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    q.push(1);
    visited[n-1][0] = true;
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            int curr = q.front();
            q.pop();
            if (curr == n * n) {
                return steps;
            }
            for (int k = 1; k <= 6; k++) {
                if (k + curr > n * n) {
                    break;
                }
                vector<int> pos = find_coordinates(k + curr, n);
                int r = pos[0];
                int c = pos[1];
                if (visited[r][c]) {
                    continue;
                }
                visited[r][c] = true;
                if (board[r][c] == -1) {
                    q.push(k + curr);
                } else {
                    q.push(board[r][c]);
                }
            }
        }
        steps++;
    }
    return -1;
}

int main(){
    
    return 0;
}