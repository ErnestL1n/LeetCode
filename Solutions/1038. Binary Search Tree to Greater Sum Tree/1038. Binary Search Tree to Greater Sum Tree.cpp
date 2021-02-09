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
    TreeNode* bstToGst(TreeNode* root) {
        stack<TreeNode*> stk;
        int value=0;
        TreeNode* curr=root;
        while(stk.size()||curr){
            while(curr){
                stk.push(curr);
                curr=curr->right;
            }
            curr=stk.top();
            stk.pop();
            curr->val+=value;
            value=curr->val;
            curr=curr->left;
        }
        return root;
    }
};

class Solution {
public:
    int value=0;
    TreeNode* bstToGst(TreeNode* root) {
        if(root->right)bstToGst(root->right);
        value=root->val=root->val+value;
        if(root->left)bstToGst(root->left);
        return root;
    }
};