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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(root,targetSum,tmp,res);
        return res;
    }
    void dfs(TreeNode* root,int sum,vector<int>& tmp,vector<vector<int>>& res){
        if(!root){
            return;
        }
        tmp.push_back(root->val);
        if(!root->left and !root->right and sum==root->val)
            res.push_back(tmp);
        if(root->left)
            dfs(root->left,sum-root->val,tmp,res);
        if(root->right)
            dfs(root->right,sum-root->val,tmp,res);
        tmp.pop_back();
    }
};