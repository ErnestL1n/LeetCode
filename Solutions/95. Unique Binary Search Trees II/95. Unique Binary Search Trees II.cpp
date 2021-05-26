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
    vector<TreeNode*> generateTrees(int n) {
        return foo(1,n);
    }
    vector<TreeNode*> foo(int start,int end){
        vector<TreeNode*> list;
        if(start>end)
            list.push_back(nullptr);
        for(int i=start;i<=end;++i){
            auto leftlist=foo(start,i-1);
            auto rightlist=foo(i+1,end);
            for(auto left:leftlist)
                for(auto right:rightlist){
                    TreeNode* root=new TreeNode(i);
                    root->left=left;
                    root->right=right;
                    list.push_back(root);
                }
        }
        return list;
    }
};