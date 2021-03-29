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
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        if(!root)
            return true;
        if(root->left and root->left->val!=root->val)
            return false;
        if(root->right and root->right->val!=root->val)
            return false;
        return isUnivalTree(root->left) and isUnivalTree(root->right);
    }
};


//stack iterative
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        if(!root)return true;
        stack<TreeNode*> stk;
        stk.push(root);
        while(stk.size()){
            auto curr=stk.top();
            stk.pop();
            if(curr->val!=root->val)
                return false;
            if(curr->right)
                stk.push(curr->right);
            if(curr->left)
                stk.push(curr->left);
        }
        return true;
    }
};


//queue iterative
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        if(!root)return true;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            auto curr=q.front();
            q.pop();
            if(curr->val!=root->val)
                return false;
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
        return true;
    }
};