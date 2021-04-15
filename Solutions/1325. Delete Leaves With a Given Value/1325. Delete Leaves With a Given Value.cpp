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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(!root)return nullptr;
        root->left=root->left?removeLeafNodes(root->left,target):nullptr;
        root->right=root->right?removeLeafNodes(root->right,target):nullptr;
        return root->left==root->right and root->val==target?nullptr:root;
    }
};