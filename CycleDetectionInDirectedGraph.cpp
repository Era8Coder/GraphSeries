#include <bits/stdc++.h>
using namespace std;

// Time Complexity = O(V + E)
// Similar to that of DFS 
bool cycle(map<int,vector<int>> &graph, vector<bool> &visited, int curr, vector<bool> &recstack){
    visited[curr] = true;
    recstack[curr] = true;
    for(auto it : graph[curr]){
        if(recstack[it]){  // Node is already in the recursion stack, so a cycle is detected
            return true;
        } else if(!visited[it]){
            if(cycle(graph, visited, it, recstack)){  // If a cycle is found in the recursion
                return true;
            }
        }
    }
    recstack[curr] = false;  // Backtrack: remove the node from the recursion stack
    return false;  // No cycle found from this node
}

void make_edge(map<int,vector<int>> &graph, int src, int dest){
    graph[src].push_back(dest);  // Making a directed Edge
}

int main(){
    map<int,vector<int>> graph;
    make_edge(graph, 1, 0);
    make_edge(graph, 0, 2);
    make_edge(graph, 2, 3);
    make_edge(graph, 3, 0);
    
    vector<bool> visited(4, false);
    vector<bool> recstack(4, false);
    bool flag = false;
    
    for(int i = 0; i < 4; i++){
        if(!visited[i]){
            if(cycle(graph, visited, i, recstack)){
                flag = true;
                break;
            }
        }
    }
    if(flag){
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}
