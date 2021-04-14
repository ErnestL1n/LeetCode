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
    int sumEvenGrandparent(TreeNode* root) {
        return dfs(root,nullptr,nullptr);
    }
    int dfs(TreeNode* curr,TreeNode* parent,TreeNode* grandp){
        int res=0;
        if(!curr)return res;
        if(grandp and grandp->val%2==0)
            res+=curr->val;
        res+=dfs(curr->left,curr,parent);
        res+=dfs(curr->right,curr,parent);
        return res;
    }
};

class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        int res=0;
        if(!root)return res;
        queue<array<TreeNode*,3>>> q;
        // cur,parent,grandpa
        q.push({root,nullptr,nullptr});
        while(q.size()){
            int qsz=q.size();
            int cur=q.front();q.pop();
            while(qsz--){
                res+=cur[2] and cur[2]
            }
        }
        return res;
    }
};