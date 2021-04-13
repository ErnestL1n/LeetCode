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
    int sumEvenGrandparent(TreeNode* root) {
        return dfs(root,nullptr,nullptr);
    }
    int dfs(TreeNode* curr,TreeNode* parent,TreeNode* grandp){
        int res=0;
        if(!curr)return res;
        if(grandp and grandp->val%2==0)
            res+=curr->val;
        res+=dfs(curr->left,curr,parent);
        res+=dfs(curr->right,curr,parent);
        return res;
    }
};