/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 //Recursive
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return sum(root,0); 
    }
    int sum(TreeNode* n,int s){
        if(!n)return 0;
        if(n->right==nullptr&&n->left==nullptr)
            return s*10+n->val;
        return sum(n->left,s*10+n->val)+sum(n->right,s*10+n->val);
    }
};

//BFS queue
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        queue<TreeNode*> q;
        int res=0;
        if(!root)return 0;
        q.push(root);
        while(q.size()){
            auto curr=q.front();q.pop();
            if(curr->left==nullptr&&curr->right==nullptr)
                res+=curr->val;
            if(curr->left){
                curr->left->val+=10*curr->val;
                q.push(curr->left);
            }
            if(curr->right){
                curr->right->val+=10*curr->val;
                q.push(curr->right);
            }
        }
        return res;
    }
};
