//BFS
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j){
                if(mat[i][j]==0){
                    q.push({i,j});
                }else
                    mat[i][j]=INT_MAX;
            }
        vector<pair<int,int>> dirs={{-1,0},{1,0},{0,1},{0,-1}};
        while(q.size()){
            auto [i,j]=q.front();q.pop();
            for(const auto& [a,b]:dirs){
                int x=a+i,y=b+j;
                if(x<0 or x>=n or y<0 or y>=m or mat[x][y]<=1+mat[i][j])
                    continue;
                q.push({x,y});
                mat[x][y]=mat[i][j]+1;
            }
        }
        return mat;
    }
};



//dp
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j){
                if(matrix[i][j]!=0){
                    matrix[i][j]=0x7fffffff;
                    int upmin=i>0?matrix[i-1][j]+1:m*n;
                    int leftmin=j>0?matrix[i][j-1]+1:m*n;
                    matrix[i][j]=min(min(leftmin,upmin),matrix[i][j]);                  
                    }
            }
        for(int i=m-1;i>=0;--i)
            for(int j=n-1;j>=0;--j){
                if(matrix[i][j]!=0){
                    int downmin=i<m-1?matrix[i+1][j]+1:m*n;
                    int rightmin=j<n-1?matrix[i][j+1]+1:m*n;
                    matrix[i][j]=min(min(rightmin,downmin),matrix[i][j]);
                    }
            }
        return matrix;
    }
};