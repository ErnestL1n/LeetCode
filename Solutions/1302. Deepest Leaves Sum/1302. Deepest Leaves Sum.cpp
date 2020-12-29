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
    int maxlevel=0,sum=0;
    int deepestLeavesSum(TreeNode* root) {
        deep(root,0);
        return sum;
    }
    void deep(TreeNode* root,int level){
        if(root){
            deep(root->left,level+1);
            deep(root->right,level+1);
            if(!root->left&&!root->right&&maxlevel<=level){
                if(maxlevel<level){
                    sum=root->val;
                    maxlevel=level;
                }else{
                    sum+=root->val;
                }
            }
        }
    }
};