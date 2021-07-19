/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */




//iterative
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root){
            if(root->val>p->val and root->val>q->val)
                root=root->left;
            else if(root->val<p->val and root->val<q->val)
                root=root->right;
            else
                return root;
        }
        return nullptr;
    }
};