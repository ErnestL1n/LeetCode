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
    int pathSum(TreeNode* root, int targetSum) {
        if(!root)
            return 0;
        return foo(root,0,targetSum)+pathSum(root->left,targetSum)+pathSum(root->right,targetSum); 
    }
    int foo(TreeNode* root,int cur,int& tsum){
        if(!root)
            return 0;
        cur+=root->val;
        return (cur==tsum)+foo(root->left,cur,tsum)+foo(root->right,cur,tsum);
    }
};