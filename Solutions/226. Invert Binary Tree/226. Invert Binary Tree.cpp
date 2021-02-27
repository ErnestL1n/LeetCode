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
            TreeNode* temp=root->left;
            root->left=invertTree(root->right);
            root->right=invertTree(temp);
        }
        return root;
    }
};



class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> stk;
        stk.push(root);
        while(stk.size()){
            auto tmp=stk.top();
            stk.pop();
            if(tmp){
                stk.push(tmp->left);
                stk.push(tmp->right);
                swap(tmp->left,tmp->right);
            }
        }
        return root;
    }
};