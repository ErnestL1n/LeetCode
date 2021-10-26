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
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            auto cur=q.front();q.pop();
            if(cur){
                q.push(cur->left);
                q.push(cur->right);
                swap(cur->left,cur->right);
            }
        }
        return root;
    }
};

