class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        bool a,b,c,d;
        a=b=c=d=true;
        int n=mat.size();
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j){
                // 0 degree
                if(mat[i][j]!=target[i][j])
                    a=false;
                // 90 degree
                if(mat[j][n-1-i]!=target[i][j])
                    b=false;
                // 180 degree
                if(mat[n-1-i][n-1-j]!=target[i][j])
                    c=false;
                // 270 degree
                if(mat[n-1-j][i]!=target[i][j])
                    d=false;
            }
        return a or b or c or d;
    }
};