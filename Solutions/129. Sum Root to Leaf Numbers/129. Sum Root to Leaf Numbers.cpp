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
    int sumNumbers(TreeNode* root) {
        return sum(root,0); 
    }
    int sum(TreeNode* n,int s){
        if(!n)return 0;
        if(n->right==nullptr&&n->left==nullptr)
            return s*10+n->val;
        return sum(n->left,s*10+n->val)+sum(n->right,s*10+n->val);
    }
};