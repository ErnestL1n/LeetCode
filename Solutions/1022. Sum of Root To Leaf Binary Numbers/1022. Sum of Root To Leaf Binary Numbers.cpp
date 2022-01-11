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
    int sumRootToLeaf(TreeNode* root,int val=0) {
        if(!root){
            return 0;
        }
        val=val*2+root->val;
        return !root->left and !root->right?val:sumRootToLeaf(root->left,val)+sumRootToLeaf(root->right,val);
    }
};

//iterative
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        int res=0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(q.size()){
            auto [cur,pre_val]=q.front();q.pop();
            pre_val=pre_val*2+cur->val;
            if(!cur->left and !cur->right){
                res+=pre_val;
            }
            if(cur->left){
                q.push({cur->left,pre_val});
            }
            if(cur->right){
                q.push({cur->right,pre_val});
            }
        }
        return res;
    }
};