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
    int res=0;
    int minCameraCover(TreeNode* root) {
        if(dfs(root)<1){
            return res+1;
        }else{
            return res;
        }
    }
    int dfs(TreeNode* root){
        if(!root){
            return 2;
        }
        int left=dfs(root->left),right=dfs(root->right);
        if(left==0 or right==0){
            ++res;
            return 1;
        }
        return left==1 or right==1?2:0;
    }
};