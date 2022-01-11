/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int dfs(struct TreeNode*,int);

int sumRootToLeaf(struct TreeNode* root){
    return dfs(root,0);
}

int dfs(struct TreeNode* root,int val){
    if(!root){
        return 0;
    }
    val=val*2+root->val;
    return !root->left && !root->right?val:dfs(root->left,val)+dfs(root->right,val);
}