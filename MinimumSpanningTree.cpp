#include<bits/stdc++.h>
using namespace std;

/*
        A MST is a subset of edges of a connected.
        Edge weighted un-directed graph that connects all 
        the vertices together, without any cycles 
        and with the minimum possible total edge weight 
        //      Here we will use Prims's Algorithm      \\
*/

void primsalgo(map<int,vector<pair<int,int>>> &graph, int V){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minheap;
    vector<bool> visited(V,false);
    minheap.push(make_pair(0,0));
    int mstCost = 0;
    /*
        -->> My second element is the Cost in the Pair
             My First element is basically the neighbor in the Pair <<--
    */
    while(!minheap.empty()){
        pair<int,int> f = minheap.top();
        minheap.pop();
        if(!visited[f.second]){              // If we had not visited the node upon which I am currently standing :)
            visited[f.second] = true;
            mstCost = mstCost + f.first;
            for(auto it : graph[f.second]){
                int neighbor = it.second;            // -->> That is checking the neighbors of it <<--
                if(!visited[neighbor]){
                    minheap.push(make_pair(it.second,neighbor));            // Adding it's weignt 
                }
            }
        }
    }

    cout << "<<-- : Minimum Cost of the Minimum Spanning Tree : -->> " << endl;
    cout << mstCost << endl;
}

void make_edge(map<int,vector<pair<int,int>>> &graph, int u, int v, int wt){
    graph[u].push_back(make_pair(v,wt));
    graph[v].push_back(make_pair(u,wt));
}

int main(){
    map<int,vector<pair<int,int>>> graph;
    make_edge(graph, 0, 1, 10);
    make_edge(graph, 0, 2, 15);
    make_edge(graph, 0, 3, 30);
    make_edge(graph, 1, 3, 40);
    make_edge(graph, 2, 3, 50);
    int V = graph.size();
    primsalgo(graph,V);
    return 0;
}