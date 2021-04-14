/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(original==nullptr)
            return nullptr;
        if(original==target)
            return cloned;
        return getTargetCopy(original->left,cloned->left,target)?:
        getTargetCopy(original->right,cloned->right,target);
    }
};


//queue
class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(!original)return nullptr;
        queue<pair<TreeNode*,TreeNode*>> q;
        q.push({original,cloned});
        while(q.size()){
            auto cur=q.front();q.pop();
            if(cur.first==target)
                return cur.second;
            if(cur.first->left)
                q.push({cur.first->left,cur.second->left});
            if(cur.first->right)
                q.push({cur.first->right,cur.second->right});   
        }
        return nullptr;
    }
};