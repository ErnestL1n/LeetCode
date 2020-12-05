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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(res,root);
        return res;
    }
private:
    void inorder(vector<int>& res,TreeNode* root){
        if(root==nullptr)
            return;
        inorder(res,root->left);
        res.push_back(root->val);
        inorder(res,root->right);
    }
};



//iteration stack
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        while(!stk.empty()||root){
            while(root){
                stk.push(root);
                root=root->left;
            }
            root=stk.top();
            stk.pop();
            res.push_back(root->val);
            root=root->right;
        }
        return res;
    }
};