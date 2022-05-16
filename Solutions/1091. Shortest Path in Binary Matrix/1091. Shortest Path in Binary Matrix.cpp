class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int steps=0;
        queue<pair<int,int>> q;
        q.push({0,0});
        while(q.size()){
            ++steps;
            queue<pair<int,int>> q1;
            while(q.size()){
                auto cur=q.front();
                q.pop();
                if(cur.first>=0 and cur.second>=0 and cur.first<grid.size() and cur.second<grid.size() and !grid[cur.first][cur.second]){
                    grid[cur.first][cur.second]=1;
                    if(cur.first==grid.size()-1 and cur.second==grid.size()-1){
                        return steps;
                    }
                    for(int i=-1;i<2;++i){
                        for(int j=-1;j<2;++j){
                            if(i or j){
                                q1.push({cur.first+i,cur.second+j});
                            }
                        }
                    }
                }
            }
            swap(q,q1);
        }
        return -1;
    }
};