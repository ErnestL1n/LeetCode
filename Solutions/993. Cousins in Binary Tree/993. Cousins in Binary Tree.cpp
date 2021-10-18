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
    bool isCousins(TreeNode* root, int x, int y) {
        vector<pair<TreeNode*,int>> ok(2);
        foo(nullptr,root,x,y,ok,0);
        return ok[0].first!=ok[1].first and ok[0].second==ok[1].second;
    }
    void foo(TreeNode* p,TreeNode* cur,int x,int y,vector<pair<TreeNode*,int>>& ok,int depth){
        if(!cur)
            return;
        if(cur->val==x){
            ok[0].first=p;
            ok[0].second=depth;
        }
        if(cur->val==y){
            ok[1].first=p;
            ok[1].second=depth;
        }
        ++depth;
        foo(cur,cur->left,x,y,ok,depth);
        foo(cur,cur->right,x,y,ok,depth);
    }
};