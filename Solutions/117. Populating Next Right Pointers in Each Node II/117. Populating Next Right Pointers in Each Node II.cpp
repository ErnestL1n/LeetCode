/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if(root){
            q.push(root);
        }
        while(q.size()){
            int sz=q.size();
            Node* prev=nullptr;
            for(int i=0;i<sz;++i){
                auto cur=q.front();q.pop();
                cur->next=prev;
                prev=cur;
                if(cur->right){
                    q.push(cur->right);
                }
                if(cur->left){
                    q.push(cur->left);
                }
            }
        }
        return root;
    }
};