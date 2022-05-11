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
    array<int,3> dfs(TreeNode* root){
        if(!root){
            return {0,0,0};
        }
        auto p1=dfs(root->left),p2=dfs(root->right);
        int s=p1[0]+p2[0]+root->val,cnt=1+p1[1]+p2[1];
        return {s,cnt,p1[2]+p2[2]+(root->val==s/cnt)};
    }
    int averageOfSubtree(TreeNode* root) {
        return dfs(root)[2];
    }
};