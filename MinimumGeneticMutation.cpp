#include<bits/stdc++.h>
using namespace std;

/*
                Time Doesn't Heal Anything It Just Teaches You How to Live With Pain !!
                                World Ask's Me Why I Love Her ???
*/

/*
                This Problem is very important {Not For biological ONE's :')}
                    Because in this we had learnt how to use maps for assuming them as Graphs and using traversal then :)
*/


bool possible(string s1, string s2){
    int cnt = 0;
    for(int i = 0; i < 8; i++){
        if(s1[i] != s2[i]){
            cnt++;
        }
    }
    return cnt == 1;
}

int minMutation(string start, string end, vector<string>& bank) {
    if (find(bank.begin(), bank.end(), end) == bank.end()) {            // Finding that End Exists or not if it don't then we can say that solution can never be reached
        return -1;
    }
    
    map<string, vector<string>> mp;                 // -->> Creating a Graph sort of thing using MAP <<--
    int n = bank.size();                
    
    for(int i = 0; i < n; i++){
        if(possible(start, bank[i])){               // Creating a grpah from starting Node :_
            mp[start].push_back(bank[i]);
            mp[bank[i]].push_back(start);
        }
        for(int j = i + 1; j < n; j++){             // Creating Edges and Nodes which are not start one if There's no end node in band array then it's impossible to reach it
            if(possible(bank[i], bank[j])){
                mp[bank[i]].push_back(bank[j]);
                mp[bank[j]].push_back(bank[i]);
            }
        }
    }

    queue<string> q;
    map<string, int> mapping;
    for(auto &gene : bank){
        mapping[gene] = INT_MAX;
    }
    mapping[start] = 0;
    q.push(start);

    while(!q.empty()){
        string node = q.front();
        q.pop();

        for(auto &neighbor : mp[node]){ 
            if(mapping[neighbor] == INT_MAX){
                mapping[neighbor] = mapping[node] + 1;
                q.push(neighbor);
            }
        }
    }

    if(mapping[end] != INT_MAX){
        return mapping[end];
    }
    return -1;
}

int main(){
    string start = "AACCGGTT";
    string end = "AAACGGTA";
    vector<string> bank = {"AACCGGTA","AACCGCTA","AAACGGTA"};
    
    int result = minMutation(start, end, bank);
    cout << result << endl;
    return 0;
}
