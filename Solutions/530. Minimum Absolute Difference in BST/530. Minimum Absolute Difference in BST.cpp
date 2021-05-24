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

//same as leetcode 783. Just see it

class Solution {
public:
    int res=INT_MAX;
    TreeNode* prev=nullptr;
    int getMinimumDifference(TreeNode* root) {
        if(!root)
            return res;
        getMinimumDifference(root->left);
        if(prev)
            res=min(res,root->val-prev->val);
        prev=root;
        getMinimumDifference(root->right);
        return res;
    }
};