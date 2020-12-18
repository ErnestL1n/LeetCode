class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
        vector<vector<int>> res;
        vector<int> path;
        path.emplace_back(0);
        dfs(g,res,path,0);
        return res;
    }
    void dfs(vector<vector<int>>& g,vector<vector<int>>& res,vector<int>& path,int node){
        if(node==g.size()-1)
            res.push_back(path);
        for(auto i:g[node]){
            path.emplace_back(i);
            dfs(g,res,path,i);
            path.pop_back();
        }
    }
};