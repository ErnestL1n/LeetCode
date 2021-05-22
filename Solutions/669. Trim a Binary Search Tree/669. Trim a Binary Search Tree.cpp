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

//recursive
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root)
            return nullptr;
        if(root->val<low)
            return trimBST(root->right,low,high);
        if(root->val>high)
            return trimBST(root->left,low,high);
        root->left=trimBST(root->left,low,high);
        root->right=trimBST(root->right,low,high);
        return root;
    }
};


//iterative
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root)
            return nullptr;
        while(root and (root->val<low or root->val>high)){
            if(root->val<low)
                root=root->right;
            if(root->val>high)
                root=root->left;
        }
        auto d=root;
        while(d){
            while(d->left and d->left->val<low)
                d->left=d->left->right;
            d=d->left;
        }
        d=root;
        while(d){
            while(d->right and d->right->val>high)
                d->right=d->right->left;
            d=d->right;
        }
        return root;
    }
};