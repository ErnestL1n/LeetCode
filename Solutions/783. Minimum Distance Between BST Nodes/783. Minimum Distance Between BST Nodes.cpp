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
    vector<int> values;
    int minDiffInBST(TreeNode* root) {
        dfs(root);
        int res=INT_MAX;
        sort(values.begin(),values.end());
        for(int i=0;i<values.size()-1;++i)
            res=min(res,values[i+1]-values[i]);
        return res;
    }
    void dfs(TreeNode* root){
        if(root){
            values.push_back(root->val);
            dfs(root->left);
            dfs(root->right);
        }
    }
};