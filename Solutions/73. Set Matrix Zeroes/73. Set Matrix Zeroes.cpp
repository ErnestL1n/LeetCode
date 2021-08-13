class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        set<pair<int,int>> s;
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)
                if(mat[i][j]==0)
                    s.insert({i,j});
        for(auto it=s.begin();it!=s.end();++it){
            const auto& [x,y]=*it;
            for(int i=0;i<m;++i)
                mat[i][y]=0;
            for(int j=0;j<n;++j)
                mat[x][j]=0;
        }
    }
};