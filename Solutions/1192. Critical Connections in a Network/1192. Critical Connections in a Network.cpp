class Solution {
public:
    int no_rk=-2;
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        for(auto& conn:connections){
            graph[conn[0]].push_back(conn[1]);
            graph[conn[1]].push_back(conn[0]);
        }
        vector<int> rk(n,no_rk);
        vector<vector<int>> res;
        criticalConnections(graph,n,0,0,rk,res);
        return res;
    }
    int criticalConnections(vector<vector<int>>& graph,int n,int node,int myrk,vector<int>& rk,vector<vector<int>>& res){
        if(rk[node]!=no_rk){
            return rk[node];
        }
        int lowestrk=myrk;
        rk[node]=myrk;
        for(auto& neighbor:graph[node]){
            if(rk[neighbor]==myrk-1 or rk[neighbor]==n){
                continue;
            }
            int neighborrk=criticalConnections(graph,n,neighbor,myrk+1,rk,res);
            lowestrk=min(lowestrk,neighborrk);
            if(neighborrk>myrk){
                res.push_back({min(node,neighbor),max(node,neighbor)});
            }
        }
        rk[node]=n;
        return lowestrk;
    }
};