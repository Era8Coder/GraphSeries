#include<bits/stdc++.h>
using namespace std;

                        /*
                                    Here's the Code for Bellman Ford
                                                    Dijkstra's Algorithm                                    BellmanFord Algorithm
                                                        O(E+E*log(V))                   |                       O(V*E)
                                                For positive weight graphs              |               For negative weight graphs 
                                                            -->> Bellman Ford don't work for negative weight cycles <<--
                        */

void bellman_ford(map<int,vector<pair<int,int>>> &graph, int src, int V){
    vector<int> distance(V,INT_MAX);
    distance[src] = 0;

    for(int k=0; k<V-1; k++){           // O(V)
        // O(E)
        for(int i=0; i<V; i++){
            for(auto it : graph[i]){                       // NEIGHBORS OF i'th ELEMENT
                int u = i;
                int v = it.first;
                int wt= it.second;
                if(distance[i] != INT_MAX && distance[i] + wt < distance[v]){
                    distance[v] = distance[i] + wt;
                }
            }
        }
    }

  // -->> Another Loop to check negative weight cycles  -> Otherwise Bellman Ford Algorithm ensures that you get answer in "V-1" loops <<--
  for(int i=0; i<V; i++){
            for(auto it : graph[i]){                       // NEIGHBORS OF i'th ELEMENT
                int u = i;
                int v = it.first;
                int wt= it.second;
                if(distance[i] != INT_MAX && distance[i] + wt < distance[v]){
                    // distance[v] = distance[i] + wt;
                    cout << "Negative Weight Cycle Is Present" << endl;
                }
            }
        }

    for(int i=0; i<distance.size(); i++){   
        cout << distance[i] << " ";
    }
}

void make_edge(map<int,vector<pair<int,int>>> &graph, int u, int v, int wt){
    graph[u].push_back(make_pair(v,wt));
}

int main(){
    map<int,vector<pair<int,int>>> graph;
    make_edge(graph, 0, 1, 2);
    make_edge(graph, 1, 2, -4);
    make_edge(graph, 0, 2, 4);
    make_edge(graph, 2, 3, 2);
    make_edge(graph, 3, 4, 4);
    make_edge(graph, 4, 1, -1);
    int V = graph.size();
    bellman_ford(graph, 0, V);
    return 0;
}
