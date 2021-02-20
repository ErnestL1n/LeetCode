class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)
            return {0};
        vector<vector<int>> G(n);
        vector<int> indegree(n),res;
        for(auto& e:edges){
            ++indegree[e[0]],++indegree[e[1]];
            G[e[0]].push_back(e[1]),G[e[1]].push_back(e[0]);
        }
        queue<int> q;
        for(int i=0;i<n;++i)
            if(indegree[i]==1)
                q.push(i);
        while(n>=3){
            int cnt=q.size();
            while(cnt--){
                int u=q.front();
                q.pop();
                --n;
                for(auto v:G[u])
                    if(--indegree[v]==1)
                        q.push(v);
            }
        }
        while(q.size()){
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};