#include<bits/stdc++.h>
using namespace std;

void shortest_path(map<int,vector<pair<int,int>>> &graph, int src, int V){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> distance(V,INT_MAX);
    
    pq.push(make_pair(0,src));
    distance[src] = 0;

    while(!pq.empty()){             // Till Minheap get's Empty :)
        int u = pq.top().second;                // We are storing the Destination Node in the Second
        pq.pop();
        for(auto it : graph[u]){                // We are now inside the vector
            int v = it.first;
            int wt= it.second;
            if(distance[v] > distance[u] + wt){                 // Method of Relaxation
                distance[v] = distance[u] + wt;
                pq.push(make_pair(distance[v], v));
            }
        }   
    }

    for(int i=0; i<V; i++){
        cout << distance[i] << " ";
    }
}

void make_edge(map<int,vector<pair<int,int>>> &graph, int u, int v, int wt){
    graph[u].push_back(make_pair(v,wt));
}

int main(){
    map<int,vector<pair<int,int>>> graph;
    int V = 6;
    make_edge(graph, 0, 1, 2);
    make_edge(graph, 0, 2, 4);
    make_edge(graph, 1, 2, 1);
    make_edge(graph, 1, 3, 7);
    make_edge(graph, 2, 4, 3);
    make_edge(graph, 4, 3, 2);
    make_edge(graph, 3, 5, 1);
    make_edge(graph, 4, 5, 5);
    shortest_path(graph, 0, V);
    return 0;
}
