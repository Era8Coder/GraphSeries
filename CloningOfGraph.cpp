#include<bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

Node* cloneGrpah(Node* node){
    if(node == NULL){
        return NULL;
    }
    map<Node*, Node*> mp;
    queue<Node*> q;
    q.push(node);
    mp[node] = new Node(node->val);                 // Initialise with empty Neighbors Not with neighbors initially :)

    while(!q.empty()){
        Node* f = q.front();
        q.pop();

        for(auto neighbor : f->neighbors){
            if(mp.find(neighbor) == mp.end()){        // That is we had not found the neigbor of it
                mp[neighbor] = new Node(neighbor->val);            // -->> Pushing the Nodes into the Map <<--
                q.push(neighbor);
            }
            mp[f]->neighbors.push_back(mp[neighbor]);   
        } 
    }

    return mp[node];            // Returning the Clone Node corresponding to the First Node from which we had started the Cloning <<--
} 

int main(){

    return 0;
}