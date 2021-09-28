/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// sol 1 : build graph + bfs
class Solution {
public:
    unordered_map<TreeNode*,vector<TreeNode*>> g;
    void buildGraph(TreeNode* parent,TreeNode *child){
        if(parent){
            g[parent].push_back(child);
            g[child].push_back(parent);
        }
        if(child->left)
            buildGraph(child,child->left);
        if(child->right)
            buildGraph(child,child->right);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        buildGraph(nullptr,root);
        vector<int> res;
        //avoid visiting same node
        unordered_set<TreeNode*> seen;
        seen.insert(target);
        queue<TreeNode*> q;
        q.push(target);
        int dist=0;
        while(q.size()>0 and dist<=k){
            int sz=q.size();
            while(sz--){
                auto cur=q.front();q.pop();
                if(dist==k)
                    res.push_back(cur->val);
                for(auto n:g[cur]){
                    if(seen.find(n)!=seen.end())
                        continue;
                    q.push(n);
                    seen.insert(n);
                }
            }
            ++dist;
        }
        return res;
    }
};