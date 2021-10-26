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
    TreeNode* invertTree(TreeNode* root) {
        if(root){
            root->left=invertTree(root->left);
            root->right=invertTree(root->right);
            swap(root->left,root->right);
        }
        return root;
    }
};



class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return nullptr;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            auto cur=q.front();q.pop();
            if(cur->left or cur->right){
                swap(cur->left,cur->right);
            }
            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
        }
        return root;
    }
};



class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            auto curr=q.front();q.pop();
            if(curr){
                auto tmp=curr->left;
                curr->left=curr->right;q.push(curr->left);
                curr->right=tmp;q.push(curr->right);
            }
        }
        return root;
    }
};