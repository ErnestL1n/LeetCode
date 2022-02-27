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
    int widthOfBinaryTree(TreeNode* root) {
        uint64_t res=0;
        queue<pair<TreeNode*,uint64_t>> q;
        q.push({root,1});
        while(q.size()){
            int sz=q.size();
            uint64_t st=q.front().second;
            for(int i=0;i<sz;++i){
                auto cur=q.front();q.pop();
                uint64_t idx=cur.second;
                res=max(res,cur.second-st+1);
                if(cur.first->left){
                    q.push({cur.first->left,idx*2});
                }
                if(cur.first->right){
                    q.push({cur.first->right,idx*2+1});
                }
            }
        }
        return res;
    }
};