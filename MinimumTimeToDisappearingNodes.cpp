#include<bits/stdc++.h>
using namespace std;

vector<int> minimumTime(int n, vector<vector<int>> &edges, vector<int> &disappear){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,0});
    map<int,vector<pair<int,int>>> graph;
    for(int i=0; i<edges.size(); i++){
        graph[edges[i][0]].push_back(make_pair(edges[i][1],edges[i][2]));
        graph[edges[i][1]].push_back(make_pair(edges[i][0],edges[i][2]));
    }
    map<int,int> distance;
    for(int i=0; i<n; i++){
        distance[i] = INT_MAX;
    }
    distance[0] = 0;
    while(!pq.empty()){             // -->> Till the Minheap becomes empty <<--
        pair<int,int> p = pq.top();
        pq.pop();
        int curr_dist = p.first;
        int curr_node = p.second;
        if(curr_dist > distance[curr_node]){
            continue;
        }
        for(auto it : graph[curr_node]){
            int dest = it.first;
            int lenh = it.second;
            if(curr_dist + lenh < distance[dest] && curr_dist + lenh < disappear[dest]){
                distance[dest] = curr_dist + lenh;
                pq.push({curr_dist + lenh, dest});
            }
        }
    }
    vector<int> ans(n,0);
    for(int i=0; i<n; i++){
        if(distance[i] == INT_MAX){
            ans[i] = -1;
        }else{
            ans[i] = distance[i];
        }
    }
    return ans;
}

int main(){
    int n = 3;
    vector<vector<int> > edges
        = { { 0, 1, 2 }, { 1, 2, 1 }, { 0, 2, 4 } };
    vector<int> disappear = { 1, 1, 5 };
    vector<int> result = minimumTime(n, edges, disappear);
    for(auto it : result){
        cout << it << endl;
    }
    return 0;
}