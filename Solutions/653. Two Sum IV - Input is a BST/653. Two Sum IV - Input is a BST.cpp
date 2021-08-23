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
 
 //set implementation
class Solution {
public:
    unordered_set<int> s;
    bool findTarget(TreeNode* root, int k) {
        if(!root)
            return false;
        if(s.count(k-root->val))
            return true;
        s.insert(root->val);
        return findTarget(root->left,k) or findTarget(root->right,k);
    }
};



//binary search method
class Solution {
public:
    TreeNode *root;
    bool findTarget(TreeNode* root, int k) {
        if(!this->root)
            this->root=root;
        if(!root)
            return false;
        if(search(root,k-root->val))
            return true;
        return findTarget(root->left,k) or findTarget(root->right,k);
    }
    bool search(TreeNode* root,int complement){
        TreeNode* cur=this->root;
        while(cur){
            if(complement>cur->val)
                cur=cur->right;
            else if(complement<cur->val)
                cur=cur->left;
            else
                return cur==root?false:true;
        }
        return false;
    }
};