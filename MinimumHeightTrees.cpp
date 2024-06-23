#include<bits/stdc++.h>
using namespace std;

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    // -->> Edge Case <<--
    if(n == 1){
        return {0};
    }
    // Step-1 Calculating the Indegree of each vertex
    vector<int> degree(n,0);        // Calculation of indegrees <<--
    map<int,vector<int>> graph;
    for(int i=0; i<edges.size(); i++){
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);            
    }
    for(int i=0; i<n; i++){
        degree[i] += graph[i].size();
    }
    // Pushing those elements in queue which has degree = 1 :)
    queue<int> q;
    for(int i=0; i<n; i++){
        if(degree[i] == 1){
            q.push(i);
        }
    }
    // Step-3 Converging inside till we reach the Central Nodes <<-- 
    while(n>2){
        int popEle = q.size();              // number of elements which are currently in the queue <<-- Probable leaf node of every level
        n -= popEle;
        for(int i=0; i<popEle; i++){
            int f = q.front();                  // Taking out the elements from the Queue
            q.pop();
            for(auto neighbor : graph[f]){             // Elements that belong to the neighbor of "f"
                degree[neighbor]--;
                if(degree[neighbor]==1){
                    q.push(neighbor);           // Pushing the neigbor inside the Queue since it's behaving as the Leaf at that Level :)
                }
            }
        }
    }
    // Step-4 Inserting the Last One or two nodes in the Resultant Vector
    vector<int> ans;
    while(!q.empty()){
        int f = q.front();
        q.pop();
        ans.push_back(f);
    }   
    return ans;
}
int main(){
    return 0;
}