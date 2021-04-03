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
//DFS
class Solution {
public:
    vector<int> sums;
    void dfs(TreeNode* r, size_t lvl) {
      if (r != nullptr) {
        sums.resize(max(sums.size(), lvl));
        sums[lvl - 1] += r->val;
        dfs(r->left, lvl + 1);
        dfs(r->right, lvl + 1);
      }
    }
    int maxLevelSum(TreeNode* r) {
      dfs(r, 1);
      return distance(begin(sums), max_element(begin(sums), end(sums))) + 1;
    }
};



//BFS , level order traversal
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int maxsum=INT_MIN,level=0,maxlevel=0;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            ++level;
            int sum=0,qsz=q.size();
            while(qsz){
                --qsz;
                auto tmp=q.front();q.pop();
                sum+=tmp->val;
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
            }
            if(maxsum<sum){
                maxlevel=level;
                maxsum=sum;
            }
        }
        return maxlevel;
    }
};