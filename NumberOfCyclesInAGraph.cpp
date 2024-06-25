#include<bits/stdc++.h>
using namespace std;

/*
                                                            -->> // Algorithm \\ <<--
a) We will use the DFS (depth-first-search) approach to visit every graph vertex.
 
b) We will maintain a visited[] array that checks if the vertex is visited and a vistime[] 
array that stores the time when each vertex of the graph is marked visited or the DFS visit time of each node.
 
c) We define an integer timer to keep track of the DFS visit time.
 
d) If any vertex is visited for the first time, it will be marked as visited, vistime of the vertex will be updated.

e) For each visited vertex v, check its adjacent vertices. If an adjacent vertex u is already visited 
and is not the parent of v, and vistime(visited time) of vertex u is less than vertex v, a cycle exists between v and u. 

f) If any fully visited vertex is found, we will skip that node.
*/

void dfs(map<int,vector<int>> &graph, int parent, int curr, int &cycle_count, vector<int> &visitime, vector<bool> &visited, int &timer){
    visited[curr] = true;
    visitime[curr] = timer;
    timer++;
    for(auto neighbor : graph[curr]){
        if(neighbor == parent){
            continue;           // No use since we are checking parent itself
        }
        if(!visited[neighbor]){
            dfs(graph, curr, neighbor, cycle_count, visitime, visited, timer);
        }else{
            if(neighbor != parent && visitime[neighbor] < visitime[curr]){          // -->> If visited time is more than that imples that there exists a new cycle here Since it's timing is more than the parent of it <<--
                cycle_count++;
            }   
        }
    }
}

int main(){
    vector<pair<int,int>> edges = {{0,1},{1,2},{2,3},{3,4},{4,1},{4,5},{4,6},{5,6}};
    int n = 7;
    map<int,vector<int>> graph;
    for(int i=0; i<edges.size(); i++){                  // -->> Creating Undirected Graph <<--
        graph[edges[i].first].push_back(edges[i].second);
        graph[edges[i].second].push_back(edges[i].first);        
    }
    vector<bool> visited(n,false);
    int cycle_count = 0;
    int timer = 0;
    vector<int> visitime(n,0);
    dfs(graph, -1, 0, cycle_count, visitime, visited, timer);
    cout << cycle_count << endl;
    return 0;
}
