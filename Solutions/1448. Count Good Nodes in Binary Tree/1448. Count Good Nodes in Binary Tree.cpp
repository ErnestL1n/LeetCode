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

// D&C
class Solution {
public:
    int goodNodes(TreeNode* root) {
        int res=0;
        dfs(res,root,root->val);
        return res;
    }
    void dfs(int& res,TreeNode* root,int max_val){
        if(!root)
            return;
        res+=root->val>=max_val;
        max_val=max(max_val,root->val);
        dfs(res,root->left,max_val);
        dfs(res,root->right,max_val);
    }
};

// 1-liner
class Solution {
public:
    int goodNodes(TreeNode* root, int val = INT_MIN) {
        return root == nullptr ? 0 : (val <= root->val) 
        + goodNodes(root->left, max(root->val, val))
            + goodNodes(root->right, max(root->val, val));
    }
};

