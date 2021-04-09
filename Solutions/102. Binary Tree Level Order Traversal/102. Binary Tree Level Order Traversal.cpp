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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        vector<vector<int>> res;
        if(!root)
            return res;
        que.push(root);
        while(!que.empty()){
            int levelNum=que.size();
            vector<int> tmp;
            for(int i=0;i<levelNum;++i){
                if(que.front()->left!=NULL){
                    que.push(que.front()->left);
                }
                if(que.front()->right!=NULL){
                    que.push(que.front()->right);
                }
                tmp.push_back(que.front()->val);
                que.pop();
            }
            res.push_back(tmp);
        }
        return res;
    }
};


//DFS
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> levelOrder(TreeNode* root) {
        dfs(root,0);
        return res;
    }
    void dfs(TreeNode* root,int depth){
        if(root==nullptr)
        return;
        if(res.size()==depth)
        res.push_back(vector<int>());
        res[depth].push_back(root->val);
        dfs(root->left,depth+1);
        dfs(root->right,depth+1);
    }
};