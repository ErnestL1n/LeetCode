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

//To clone a graph, you will need to traverse it. 
//Both BFS and DFS are for this purpose. But that is not all you need. 
//To clone a graph, you need to have a copy of each node and you need to avoid copying the same node for multiple times. 
//So you still need a mapping from an original node to its copy.
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