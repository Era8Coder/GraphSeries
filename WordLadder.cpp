#include<bits/stdc++.h>
using namespace std;

/*
                Time Doesn't Heal Anything It Just Teaches You How to Live With Pain !!
                                World Ask's Me Why I Love Her ???
*/

/*
                        This problem is vary important to learn How to convert 
                        string problems to graph ones :)                
*/

bool possible(string s1,string s2){
    int cnt = 0;
    int n = s1.size(); 
    for(int i=0; i<n; i++){
        if(s1[i] != s2[i]){
            cnt++;
        }
    }
    return cnt == 1;            // If count = 1; then True :)
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    if(find(wordList.begin(),wordList.end(), endWord) == wordList.end()){                // We are checking that the final word exists in the WordList or not :) 
        return 0;
    }

    map<string,vector<string>> mp;
    int n = wordList.size();

    for(int i=0; i<n; i++){
        if(possible(beginWord, wordList[i])){   
            mp[beginWord].push_back(wordList[i]);
            mp[wordList[i]].push_back(beginWord);
        }
        for(int j=i+1; j<n; j++){
            if(possible(wordList[i], wordList[j])){
                mp[wordList[i]].push_back(wordList[j]);
                mp[wordList[j]].push_back(wordList[i]);
            }
        }
    }

    queue<string> q;
    map<string, int> mapping;           // For storing the distance :)

    for(auto &word : wordList){
        mapping[word] = INT_MAX;
    }

    mapping[beginWord] = 0;
    q.push(beginWord);

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

    if(mapping[endWord] != INT_MAX){
        return mapping[endWord] + 1;
    }

    return 0;
}

int main(){
    string beignWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    cout << ladderLength(beignWord, endWord, wordList) << endl;
    return 0;
}