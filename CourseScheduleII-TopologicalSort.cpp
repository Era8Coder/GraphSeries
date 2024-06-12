#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> cycle(vector<vector<int>>& graph, int V) {
        vector<int> indegree(V, 0);

        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < graph[i].size(); ++j) {
                indegree[graph[i][j]]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int cnt = 0; // Count of visited vertices
        vector<int> topo;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cnt++;
            topo.push_back(u);

            for (auto v : graph[u]) {
                if (--indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        return topo;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (const auto& pair : prerequisites) {
            graph[pair[1]].push_back(pair[0]);
        }
        return cycle(graph, numCourses);
    }
};

int main(){
    
    return 0;
}