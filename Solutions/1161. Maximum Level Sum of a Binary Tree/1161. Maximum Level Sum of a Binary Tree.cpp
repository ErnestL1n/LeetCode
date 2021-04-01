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



class Solution {
public:
    int maxLevelSum(TreeNode* r) {
      vector<TreeNode*> q{r};
      int msum = 0, lvl = 0, msum_lvl = 0;
      while (!q.empty()) {
          vector<TreeNode*> q1;
          int sum = 0;
          ++lvl;
          for (auto n : q) {
              sum += n->val;
              if (n->left != nullptr) 
                  q1.push_back(n->left);
              if (n->right != nullptr) 
                  q1.push_back(n->right);
          }
          msum_lvl = sum < msum ? msum_lvl : lvl;
          msum = max(sum, msum);
          swap(q, q1);
      }
      return msum_lvl;
    }
};