//bfs
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> colors(n);
        for(int i=0;i<n;++i){
            if(colors[i]!=0){
                continue;
            }
            queue<int> q;
            q.push(i);
            colors[i]=1;
            while(q.size()){
                auto cur=q.front();q.pop();
                for(auto& x:graph[cur]){
                    if(colors[x]==0){
                        colors[x]=-colors[cur];
                        q.push(x);
                    }else if(colors[x]!=-colors[cur]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

//dfs
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> colors(n);
        for(int i=0;i<n;++i){
            if(colors[i]==0 and !validcolor(graph,colors,1,i)){
                return false;
            }
        }
        return true;
    }
    bool validcolor(vector<vector<int>>& graph,vector<int>& colors,int color,int node){
        if(colors[node]!=0){
            return colors[node]==color;
        }
        colors[node]=color;
        for(auto& x:graph[node]){
            if(!validcolor(graph,colors,-color,x)){
                return false;
            }
        }
        return true;
    }
};