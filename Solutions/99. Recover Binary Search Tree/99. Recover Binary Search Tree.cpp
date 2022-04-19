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
    TreeNode* first=nullptr,*second=nullptr;
    TreeNode* prev=new TreeNode(INT_MIN);
    void recoverTree(TreeNode* root) {
        traverse(root);
        int tmp=first->val;
        first->val=second->val;
        second->val=tmp;
    }
    void traverse(TreeNode* root){
        if(!root){
            return;
        }
        traverse(root->left);
        if(!first and prev->val>root->val){
            first=prev;
        }
        if(first and prev->val>root->val){
            second=root;
        }
        prev=root;
        traverse(root->right);
    }
};