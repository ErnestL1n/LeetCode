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
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        return dfs(root,s,k);
    }
    bool dfs(TreeNode* root,unordered_set<int>& s,int k){
        if(!root)
            return false;    
        if(s.count(k-root->val))
            return true;
        s.insert(root->val);
        return dfs(root->left,s,k) || dfs(root->right,s,k);  
    }
};



//binary search method
class Solution {
public:
    bool findTarget(TreeNode* node, int k) {
        if(this->root==nullptr)
            this->root=node;
        if(node==nullptr)
            return false;
        if(search(node,k-node->val))
            return true;
        return findTarget(node->left,k) || findTarget(node->right,k);
    }
    bool search(TreeNode* node,int complement){
        TreeNode* curr=this->root;
        while(curr!=nullptr){
            if(complement>curr->val)
                curr=curr->right;
            else if(complement<curr->val)
                curr=curr->left;
            else
                return curr==node?false:true;
        }
        return false;
    }
    
private:
    TreeNode* root;
};