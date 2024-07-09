#include <vector>
#include <queue>
#include <map>
#include <utility>
using namespace std;

void BFS(map<int, vector<int>>& graph, vector<int>& colors, int start) {
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        vector<bool> used(5, false); // To mark used colors, since colors are 1 to 4
        // Mark all colors of adjacent nodes as used
        for (int neighbor : graph[node]) {
            if (colors[neighbor] != 0) {
                used[colors[neighbor]] = true;
            }
        }
        // Assign the first available color to the current node
        for (int c = 1; c <= 4; ++c) {
            if (!used[c]) {
                colors[node] = c;
                break;
            }
        }
        // Traverse all neighbors
        for (int neighbor : graph[node]) {
            if (colors[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
}

vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
    map<int, vector<int>> graph;
    for (const auto& path : paths) {
        graph[path[0]].push_back(path[1]);
        graph[path[1]].push_back(path[0]);
    }
    vector<int> colors(n + 1, 0); // Color assignments for each node
    // Perform BFS for each unvisited node
    for (int i = 1; i <= n; ++i) {
        if (colors[i] == 0) {
            BFS(graph, colors, i);
        }
    }
    // Remove the 0-th index and return the result
    return vector<int>(colors.begin() + 1, colors.end());
}

int main(){

    return 0;
}