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
    int sum=0;
    TreeNode* convertBST(TreeNode* root) {
        reverse_inorder(root);
        return root;
    }
    void reverse_inorder(TreeNode* root){
        if(!root){
            return;
        }
        reverse_inorder(root->right);
        root->val+=sum;
        sum=root->val;
        reverse_inorder(root->left);
        return;
    }
};