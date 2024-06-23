#include<bits/stdc++.h>
using namespace std;  
  
bool isBipartite(vector<vector<int>>& graph) {
    int V = graph.size();
    vector<int> color(V,-1);
    for(int i=0; i<V; i++){
        if(color[i] == -1){
            if(dfs(i,0,color,graph) == false){
                return false;       // return false if node = i; and color array through it
            }
        }
    }
    return true;
}

bool dfs(int node, int col, vector<int> &color, vector<vector<int>> &graph){            // pass by reference since they are modified when we are making changes
    color[node] = col;          // mark it with new color
    for(auto it : graph[node]){
        if(color[it] == -1){
            if(dfs(it,!col,color,graph) == false){
                return false;
            }
        }else if(color[it] == col){
            return false;
        }
    }
    return true;
}

int main(){

    return 0;
}