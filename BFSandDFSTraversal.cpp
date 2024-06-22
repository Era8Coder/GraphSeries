#include<bits/stdc++.h>
using namespace std;

                    /*
                            That's All Ladies and Gentle man
                            -->> Time Doesn't Heal Anything It just teaches you How to live with Pain <<-- 
                    */

// BFS      -> INDIRECT LEVEL ORDER TRAVERSAL
/*
                Time Complexity -> O(V + E)
*/
void BFS(map<int,vector<int>> &graph, int start, int V, vector<bool> &visited){     // We can also define visited inside but in functino for discconnected components we use it 
    queue<int> q;
    q.push(start);
    // vector<bool> visited(V,false);

    while(!q.empty()){
        int f = q.front();
        q.pop();

        if(!visited[f]){                // If that node is not visited
            cout << f << " ";
            visited[f] = true;          // -->> As you visit that Node mark it true <<--
            for(auto it : graph[f]){  
                q.push(it);
            }
        }
    }
}

// DFS      -> BASICALLY TRAVERSING TO DEPTH AS MUCH AS POSSIBLE 
void DFS(map<int,vector<int>> &graph, int curr, vector<bool> &visited){
    cout << curr << " ";
    visited[curr] = true;
    int V = graph.size();

    for(auto it : graph[curr]){
        if(!visited[it]){           // if it's not visited
            DFS(graph,it,visited);              // Calling DFS Recursively                  
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
    // make_edge(graph,5,6);
    int V = 7;
    int start = 0;
    vector<bool> visited(V,false);
    cout << "BFS Traversal of the Graph Made By Us : " << endl;
    // BFS(graph,start,V,visited);          // Normal BFS Traversal For Single connected Component
    int number_of_connected_components = 0;
    for(int i=0; i<V; i++){
        if(!visited[i]){
            number_of_connected_components++;
            BFS(graph,i,V,visited);
            cout << endl;
        }
    }
    cout << "Number of Connected Components : " << endl;
    cout << number_of_connected_components << endl;
    cout << endl;
    cout << "DFS Traversal of the Graph Made By Us : " << endl;
    vector<bool> vsted(V, false);
    int curr = 0;
    int NumberOfConnectedComponents = 0;
    for(int i=0; i<V; i++){
        if(!vsted[i]){
            NumberOfConnectedComponents++;
            DFS(graph, i, vsted);
            cout << endl;
        }
    }
    cout << "Number of Connected Components : " << endl;
    cout << NumberOfConnectedComponents << endl;
    // DFS(graph, curr, vsted);
    return 0;
}