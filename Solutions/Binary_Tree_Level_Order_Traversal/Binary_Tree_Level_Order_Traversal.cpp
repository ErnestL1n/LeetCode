/**
 * @author https://github.com/ErnestL1n
 *
 */
 //Leetcode.102
#include<vector>
#include<iostream>
#include<queue>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        vector<vector<int>> res;
        if(root==nullptr)
            return res;
        que.push(root);
        while(!que.empty()){
            int levelNum=que.size();
            vector<int> sublist;
            for(int i=0;i<levelNum;++i){
                if(que.front()->left!=NULL){
                    que.push(que.front()->left);
                }
                if(que.front()->right!=NULL){
                    que.push(que.front()->right);
                }
                sublist.push_back(que.front()->val);
                que.pop();
            }
            res.push_back(sublist);
        }
        return res;
    }

    //DFS version
    vector<vector<int>> res;
    vector<vector<int>> levelOrderDFS(TreeNode* root) {
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
int main(){
    cout << "test program";
    return 0;
}