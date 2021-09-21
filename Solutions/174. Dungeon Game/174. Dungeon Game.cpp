class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& d) {
        int m=d.size(),n=d[0].size();
        vector<vector<int>> hp(m+1,vector<int>(n+1,INT_MAX));
        hp[m-1][n]=hp[m][n-1]=1;
        for(int i=m-1;i>=0;--i)
            for(int j=n-1;j>=0;--j){
                hp[i][j]=max(1,min(hp[i][j+1],hp[i+1][j])-d[i][j]);
            }
        return hp[0][0];
    }
};