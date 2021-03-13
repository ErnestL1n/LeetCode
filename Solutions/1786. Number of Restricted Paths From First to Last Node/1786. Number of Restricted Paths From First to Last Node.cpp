//dfs+bfs(dijkstra)
typedef pair<int,int> pr;
class Solution {
public:
    int mod=1e9+7;
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pr>> G(n+1);
        vector<int> dist(n+1),dp(n+1,-1);
        for(auto& e:edges){
            G[e[0]].push_back({e[1],e[2]});
            G[e[1]].push_back({e[0],e[2]});
        }
        priority_queue<pr,vector<pr>,greater<pr>> pq;
        pq.push({0,n});
        while(pq.size()){
            auto [dis,i]=pq.top();pq.pop();
            for(auto [j,w]:G[i]){
                if(j!=n&&(dist[j]==0||dist[j]>dist[i]+w)){
                    dist[j]=dist[i]+w;
                    pq.push({dist[j],j});
                }
            }
        }
        return dfs(G,dist,dp,n);
    }
    int dfs(vector<vector<pr>>& G,vector<int>& dist,vector<int>& dp,int i){
        //we begin from n
        //thus distanceToLastNode(n) must less than 
        //distanceToLastNode(1~n-1) to form a Restricted Path
        if(i==1)
            return 1;
        if(dp[i]==-1){
            dp[i]=0;
            for(auto [j,w]:G[i])
                if(dist[i]<dist[j])
                    //runtime error: signed integer overflow
                    //dp[i]+=dp[i]+dfs(G,dist,dp,j);
                    dp[i]=(dp[i]+dfs(G,dist,dp,j))%mod;
        }
        return dp[i];
    }
};



//make dijkstra's algorithm a function
typedef pair<int,int> pr;
class Solution {
public:
    int mod=1e9+7;
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pr>> G(n+1);
        vector<int> dp(n+1,-1);
        for(auto& e:edges){
            G[e[0]].push_back({e[1],e[2]});
            G[e[1]].push_back({e[0],e[2]});
        }
        vector<int> dist=dijkstra(G,n);
        return dfs(G,dist,dp,n);
    }
    vector<int> dijkstra(vector<vector<pr>>& G,int n){
        vector<int> dist(n+1);
        priority_queue<pr,vector<pr>,greater<pr>> pq;
        pq.push({0,n});
        while(pq.size()){
            auto [dis,i]=pq.top();pq.pop();
            for(auto [j,w]:G[i]){
                if(j!=n&&(dist[j]==0||dist[j]>dist[i]+w)){
                    dist[j]=dist[i]+w;
                    pq.push({dist[j],j});
                }
            }
        }
        return dist;
    }
    int dfs(vector<vector<pr>>& G,vector<int>& dist,vector<int>& dp,int i){
        //we begin from n
        //thus distanceToLastNode(n) must less than 
        //distanceToLastNode(1~n-1) to form a Restricted Path
        if(i==1)
            return 1;
        if(dp[i]==-1){
            dp[i]=0;
            for(auto [j,w]:G[i]){
                if(dist[j]>dist[i])
                    //runtime error: signed integer overflow
                    //dp[i]+=dp[i]+dfs(G,dist,dp,j);
                    dp[i]=(dp[i]+dfs(G,dist,dp,j))%mod;       
            }
        }
        return dp[i];
    }
};