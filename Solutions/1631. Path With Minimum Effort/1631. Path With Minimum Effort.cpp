class Solution {
public:
    vector<array<int,2>> dirs={{-1,0},{1,0},{0,1},{0,-1}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size(),n=heights[0].size();
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>> pq;
        pq.push({0,0,0});
        while(pq.size()){
            auto [d,r,c]=pq.top();pq.pop();
            if(d>dist[r][c]){
                continue;
            }
            if(r==m-1 and c==n-1){
                return d;
            }
            for(auto& dir:dirs){
                int x=dir[0]+r,y=dir[1]+c;
                if(x>=0 and x<m and y>=0 and y<n){
                    int tmp=max(d,abs(heights[x][y]-heights[r][c]));
                    if(dist[x][y]>tmp){
                        dist[x][y]=tmp;
                        pq.push({tmp,x,y});
                    }
                }
            }
        }
        return -1;
    }
};