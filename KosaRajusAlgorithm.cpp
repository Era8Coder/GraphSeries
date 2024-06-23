#include <bits/stdc++.h>
using namespace std;

/*
                -->> Here we are going to explore the Kosaraju's Algorithm to find the Strongly Connected Components <<--
                       SCC => We can reach every vertex of the component from every other vertex in that component
                                        Kosaraju's Algo -->> Works on the principle of Reverse dfs 
                        Algorithm =>
                            -->>
                            a) Get nodes in the stack {Topological Order}                                                   \\ O(V+E)
                            b) Transpose the Graph {Basically to reverse all the Edges in the graph which is given to us :)} \\ O(V+E)
                            c) Do dfs according to nodes in the stack on the transpose graph                                  \\ O(V+E)  
                            <<--
                                                Overall Time Complexity => O(V+E)
*/

void make_edge(map<int,vector<int>> &graph, int u, int v){                  // -->> To make the directed Graph <<--
    graph[u].push_back(v);
}

void topSort(map<int,vector<int>> &graph, int curr, vector<bool> &visited, stack<int> &stk){
    visited[curr] = true;
    for(auto it : graph[curr]){
        if(!visited[it]){                   // That is graph[curr] -> we are basically traversing the vector
            topSort(graph, it, visited, stk);
        }
    }
    stk.push(curr);
}

void dfs(map<int,vector<int>> &graph, int curr, vector<bool> &visited){
    visited[curr] = true;
    cout << curr << " ";
    for(int i=0; i<graph[curr].size(); i++){
        if(!visited[graph[curr][i]]){
            dfs(graph, graph[curr][i], visited);
        }
    }
}

void kosaraju_algo(map<int,vector<int>> &graph, int V){
    // Step 1 -> Creating Stack <<-- 
    stack<int> stk;
    vector<bool> visited(V, false);
    for(int i=0; i<V; i++){
        if(!visited[i]){
            topSort(graph, i, visited, stk);
        }
    }

    // Step 2 -> Transposing the Graph <<--  
    map<int,vector<int>> transpose;
    for(int i=0; i<V; i++){
        for(auto it : graph[i]){
            transpose[it].push_back(i);     // Correctly transpose: reverse direction of all edges
        }
    }

    // Step 3 -> DFS on Transposed Graph according to finishing times <<--
    fill(visited.begin(), visited.end(), false); // Reset visited array

    while(!stk.empty()){
        int curr = stk.top();
        stk.pop();
        if(!visited[curr]){
            dfs(transpose, curr, visited); // Perform DFS on the transposed graph
            cout << endl;
        }
    }
}

int main(){
    map<int,vector<int>> graph;
    make_edge(graph, 0, 3);
    make_edge(graph, 3, 4);
    make_edge(graph, 0, 2);
    make_edge(graph, 2, 1);
    make_edge(graph, 1, 0);
    int V = 5; // Define the number of vertices
    kosaraju_algo(graph, V);
    return 0;
}
