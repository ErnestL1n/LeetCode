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
    int sumOfLeftLeaves(TreeNode* root) {
        int res=0;
        stack<TreeNode*> stk;
        stk.push(root);
        while(stk.size()){
            auto cur=stk.top();stk.pop();
            if(cur->left){
                if(!cur->left->left and !cur->left->right){
                    res+=cur->left->val;
                }else{
                    stk.push(cur->left);
                }
            }
            if(cur->right){
                if(cur->right->left or cur->right->right){
                    stk.push(cur->right);
                }
            }
        }
        return res;
    }
};


class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root,TreeNode* parent=nullptr) {
        int res=0;
        function<void(TreeNode*,TreeNode*)> dfs=[&](TreeNode* parent,TreeNode* root){
            if(root){
                dfs(root,root->left);
                dfs(root,root->right);
                if(root->left==nullptr and root->right==nullptr and parent and root==parent->left){
                    res+=root->val;
                }
            }
        };
        dfs(parent,root);
        return res;
    }
}; 