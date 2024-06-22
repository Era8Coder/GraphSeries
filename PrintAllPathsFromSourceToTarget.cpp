#include<bits/stdc++.h>
using namespace std;


// Time Complexity -> O(V^V) => Exponential Time Complexity
void DFS(map<int,vector<int>> &graph, vector<bool> &visited, int target, string path, int curr){
    // path += to_string(curr) + " ";   
    
    if(curr == target){ 
        cout << path + to_string(target) << endl;
        return;
    }

    for(auto it : graph[curr]){             // To visit all the neighbors of the current one
        if(!visited[it]){
            visited[it] = true;
            DFS(graph, visited, target, path + to_string(curr) + " ", it);            // -->> Recursive Calls <<--
            visited[it] = false;
        }
    }
}

void make_edge(map<int,vector<int>> &graph, int u, int v){              // undirected graph
    graph[u].push_back(v);
    graph[v].push_back(u);
}

int main(){
    map<int,vector<int>> graph;
    make_edge(graph,0,1);
    make_edge(graph,0,2);
    make_edge(graph,1,3);
    make_edge(graph,2,4);
    make_edge(graph,3,4);
    make_edge(graph,3,5);
    make_edge(graph,4,5);
    make_edge(graph,5,6);
    int start = 0;
    int target = 5;
    int V = 7;
    vector<bool> visited(V,false);
    string path = "";
    visited[start] = true;
    DFS(graph, visited, target, path, start);
    return 0;
}
