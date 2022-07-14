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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfs(0,0,inorder.size()-1,preorder,inorder);
    }
    TreeNode* dfs(int prestart,int instart,int inEnd,vector<int>& preorder,vector<int>& inorder){
        if(prestart>preorder.size()-1 or instart>inEnd){
            return nullptr;
        }
        TreeNode* root=new TreeNode(preorder[prestart]);
        int idx=0;
        for(int i=instart;i<=inEnd;++i){
            if(inorder[i]==root->val){
                idx=i;
            }
        }
        root->left=dfs(prestart+1,instart,idx-1,preorder,inorder);
        root->right=dfs(prestart+idx-instart+1,idx+1,inEnd,preorder,inorder);
        return root;
    }
};