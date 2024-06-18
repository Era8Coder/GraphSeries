#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>

using namespace std;

void bfs(map<string,vector<pair<string,double>>> &graph, string src, string dst, set<string> &visited, double prod, double &ans){
    queue<pair<string, double>> q;
    q.push({src, 1.0});
    
    while(!q.empty()){
        auto f = q.front().first;
        auto prod = q.front().second;
        q.pop();
        
        if (visited.find(f) != visited.end()) {
            continue;
        }
        
        visited.insert(f);
        
        if(f == dst){                                           // If you reach the string then return the product :_
            ans = prod;
            return;
        }

        for(auto &neighbor : graph[f]){                 // Checking the Neighbors of the current node
            string str = neighbor.first;
            double val = neighbor.second;
            if (visited.find(str) == visited.end()) {           // If the string is not in visited then pushs the old string and the product
                q.push({str, prod * val});                              
            }
        }
    }
}

vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    int n = equations.size();
    map<string,vector<pair<string,double>>> graph;             // -->> Creation of Graph <<--       
    for(int i=0; i<n; i++){
        string u = equations[i][0];
        string v = equations[i][1];
        double val = values[i];
        graph[u].push_back(make_pair(v, val));
        graph[v].push_back(make_pair(u, 1.0 / val));                        // Creating an Undirected Graph
    } 

    vector<double> res;
    for(int i=0; i<queries.size(); i++){                  //    O(N) -> Number of Queries
        string src = queries[i][0];
        string dst = queries[i][1];
        double ans = -1;
        if(graph.find(src) != graph.end() && graph.find(dst) != graph.end()){         // If "src" and "dst" are found in the graph
            set<string> visited;
            bfs(graph, src, dst, visited, 1.0, ans);                        // Graph Traversal Using BFS 
        }
        res.push_back(ans);
    }
    return res;
}

int main(){
    vector<vector<string>> equations = {{"a","b"},{"b","c"}};
    vector<double> values = {2.0, 3.0};
    vector<vector<string>> queries = {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};   
    vector<double> ans = calcEquation(equations,values,queries);
    for (double val : ans) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
