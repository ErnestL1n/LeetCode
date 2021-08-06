/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(!root)
            return res;
        vector<int> tmp;
        queue<Node*> q;
        q.push(root);
        while(q.size()){
            tmp.clear();
            int sz=q.size();
            for(int i=0;i<sz;++i){
                auto cur=q.front();q.pop();
                tmp.push_back(cur->val);
                for(int j=0;cur->children.size()>0 and j<cur->children.size();++j)
                    q.push(cur->children[j]);
            }
            res.push_back(tmp);
        }
        return res;
    }
};