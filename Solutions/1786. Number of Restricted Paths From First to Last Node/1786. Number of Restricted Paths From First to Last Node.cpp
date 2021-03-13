//TLE
typedef pair<int,int> pr;
class Solution {
public:
    int mod=1e9+7;
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        if(n==1)
            return 0;
        vector<vector<pr>> G(n+1);
        for(auto& e:edges){
            G[e[0]].push_back({e[1],e[2]});
            G[e[1]].push_back({e[0],e[2]});
        }
        vector<int> dist=dijkstra(G,n);
        vector<int> dp(n+1);
        return dfs(1,n,G,dist,dp);
    }
    vector<int> dijkstra(vector<vector<pr>>& G,int n){
        vector<int> dist(n+1,INT_MAX);
        dist[n]=0;
        priority_queue<pr,vector<pr>,greater<pr>> pq;
        pq.push({0,n});
        while(pq.size()){
            auto curr=pq.top();
            pq.pop();
            int d=curr.first,u=curr.second;
            if(d!=dist[u])
                continue;
            for(auto& nei:G[u]){
                int v=nei.first,w=nei.second;
                if(dist[v]>dist[u]+w){
                    dist[v]=dist[u]+w;
                    pq.push({dist[v],v});
                }
            }
        }
        return dist;
    }
    int dfs(int src,int n,vector<vector<pr>>& G,vector<int>& dist,vector<int>& dp){
        if(dp[src])return dp[src];
        if(src==n)return 1;
        int res=0;
        for(auto& nei:G[src]){
            int v=nei.first,w=nei.second;
            if(dist[src]>dist[v]){
                res=(res+dfs(v,n,G,dist,dp))%mod;
            }
        }
        return dp[src]=res;
    }
};