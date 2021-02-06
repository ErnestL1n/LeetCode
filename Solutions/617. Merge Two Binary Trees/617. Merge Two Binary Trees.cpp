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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1)return t2?t2:nullptr;
        if(!t2)return t1;
        t1->left=mergeTrees(t1->left,t2->left);
        t1->right=mergeTrees(t1->right,t2->right);
        t1->val+=t2->val;
        return t1;
    }
};



typedef array<TreeNode*,2> ar;
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1)return t2?t2:nullptr;
        if(!t2)return t1;
        stack<ar> stk;
        stk.push({t1,t2});
        while(stk.size()){
            auto& curr=stk.top();
            stk.pop();
            if(!curr[0]||!curr[1])
                continue;
            curr[0]->val+=curr[1]->val;
            if(!curr[0]->left&&curr[1]->left)
                curr[0]->left=curr[1]->left;
            else
                stk.push({curr[0]->left,curr[1]->left});
            if(!curr[0]->right&&curr[1]->right)
                curr[0]->right=curr[1]->right;
            else
                stk.push({curr[0]->right,curr[1]->right});
        }
        return t1;
    }
};