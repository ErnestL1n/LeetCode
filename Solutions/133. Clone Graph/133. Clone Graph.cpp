/*
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
*/

//bfs
class Solution {
public:
    unordered_map<Node*,Node*> copies;
    Node* cloneGraph(Node* node) {
        if(!node){
            return nullptr;
        }
        Node* copy=new Node(node->val,{});
        copies[node]=copy;
        queue<Node*> q;
        q.push(node);
        while(q.size()){
            Node* cur=q.front();q.pop();
            for(Node* n:cur->neighbors){
                if(copies.find(n)==copies.end()){
                    copies[n]=new Node(n->val,{});
                    q.push(n);
                }
                copies[cur]->neighbors.push_back(copies[n]);
            }
        }
        return copy;
    }
};