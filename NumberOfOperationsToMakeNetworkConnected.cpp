#include<bits/stdc++.h>
using namespace std;

void dfs1(map<int,vector<int>> &graph, vector<bool> &visited, int curr){
    visited[curr] = true;
    for(auto neighbor : graph[curr]){
        if(!visited[neighbor]){
            dfs1(graph, visited, neighbor);
        }
    }
}

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

int makeConnected(int n, vector<vector<int>> &connections){
    map<int, vector<int>> graph;
    for(int i=0; i<n; i++){
        graph[i];
    }
    for(int j=0; j<connections.size(); j++){
        graph[connections[j][0]].push_back(connections[j][1]);
        graph[connections[j][1]].push_back(connections[j][0]);
    }
    vector<bool> visited(n,false);
    int number_diconnected_components = 0;
    int cycle_count = 0;
    vector<int> nodes;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            number_diconnected_components++;
            nodes.push_back(i);
            dfs1(graph, visited, i);
        }
    }
    for(int i=0; i<n; i++){
        visited[i] = false;
    }
    for(int i=0; i<nodes.size(); i++){
        int timer = 0;
        vector<int> visitime(n,0);
        dfs(graph, -1, nodes[i], cycle_count, visitime, visited, timer);
    }
    if(number_diconnected_components - 1 <= cycle_count){
        return number_diconnected_components - 1;
    }
    return -1;
}

int main(){

    return 0;
}