class Solution {
public:
    int numSubmat(vector<vector<int>>& mat){
        int m=mat.size(),n=mat[0].size();
        int cnt=0;
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)
                cnt+=foo(mat,i,j);
        return cnt;
    }
    int foo(vector<vector<int>>& mat,int a,int b) {
        int res=0;
        int m=mat.size(),n=mat[0].size();
        int cnt=0;
        int bound=n;
        for(int i=a;i<m;++i)
            for(int j=b;j<bound;++j){
                if(mat[i][j])
                    ++cnt;
                else
                    bound=j;
            }
        return cnt;
    }
};