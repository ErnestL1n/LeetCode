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
    long res=0,totalsum=0;
    int mod=1e9+7;
    int maxProduct(TreeNode* root) {
        totalsum=dfs(root);
        dfs(root);
        return res%mod;
    }
    int dfs(TreeNode* root){
        if(!root)
            return 0;
        int cursum=dfs(root->left)+dfs(root->right)+root->val;
        res=max(res,(totalsum-cursum)*cursum);
        return cursum;
    }
};