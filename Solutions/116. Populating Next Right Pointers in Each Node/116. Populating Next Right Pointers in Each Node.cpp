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

//bfs with queue
class Solution {
public:
    Node* connect(Node* root) {
        if(!root){
            return nullptr;
        }
        queue<Node*> q;
        q.push(root);
        while(q.size()){
            Node* rightnode=nullptr;
            int cnt=q.size();
            while(cnt--){
                auto cur=q.front();q.pop();
                cur->next=rightnode;
                rightnode=cur;
                if(cur->right){
                    q.push(cur->right);
                    q.push(cur->left);
                }
            }
        }
        return root;
    }
};

//dfs
class Solution {
public:
    Node* connect(Node* root) {
        if(!root){
            return nullptr;
        }
        auto l=root->left,r=root->right,n=root->next;
        if(l){  //have children
            l->next=r;
            if(n){  //root has next
                r->next=n->left;
            }
            connect(l);
            connect(r);
        }
        return root;
    }
};

// bfs space opt
class Solution {
public:
    Node* connect(Node* root) {
        auto head=root;
        for(;root;root=root->left){
            for(auto cur=root;cur;cur=cur->next){
                if(cur->left){
                    cur->left->next=cur->right;
                    if(cur->next){
                        cur->right->next=cur->next->left;
                    }
                }
            }
        }
        return head;
    }
};