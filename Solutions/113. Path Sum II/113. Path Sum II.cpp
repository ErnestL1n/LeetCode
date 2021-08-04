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
//dfs recursive
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(root,targetSum,tmp,res);
        return res;
    }
    void dfs(TreeNode* root,int sum,vector<int>& tmp,vector<vector<int>>& res){
        if(!root){
            return;
        }
        tmp.push_back(root->val);
        if(!root->left and !root->right and sum==root->val)
            res.push_back(tmp);
        if(root->left)
            dfs(root->left,sum-root->val,tmp,res);
        if(root->right)
            dfs(root->right,sum-root->val,tmp,res);
        tmp.pop_back();
    }
};


//dfs using stack,iterative
// Note: bfs method is similar to dfs method while bfs using queue instead of using stack
typedef struct{
    TreeNode* root;
    int val;
    vector<int> vals;
}Node;
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        if(!root)
            return res;
        stack<Node> stk;
        stk.push({root,targetSum-root->val,{root->val}});
        while(stk.size()){
            auto curr=stk.top();stk.pop();
            if(!curr.root->left and !curr.root->right and curr.val==0)
                res.push_back(curr.vals);
            if(curr.root->right){
                curr.vals.push_back(curr.root->right->val);
                stk.push({curr.root->right,curr.val-curr.root->right->val,curr.vals});
               curr.vals.pop_back();
            }
            if(curr.root->left){
                curr.vals.push_back(curr.root->left->val);
                stk.push({curr.root->left,curr.val-curr.root->left->val,curr.vals});
                curr.vals.pop_back();
            }
        }
        return res;
    }
};