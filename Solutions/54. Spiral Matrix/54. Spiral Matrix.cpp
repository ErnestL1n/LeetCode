class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        int u=0,d=m-1,l=0,r=n-1,p=0;
        vector<int> res(m*n);
        while(u<=d and l<=r){
            for(int col=l;col<=r;++col)
                res[p++]=mat[u][col];
            if(++u>d)
                break;
            for(int row=u;row<=d;++row)
                res[p++]=mat[row][r];
            if(--r<l)
                break;
            for(int col=r;col>=l;--col)
                res[p++]=mat[d][col];
            if(--d<u)
                break;
            for(int row=d;row>=u;--row)
                res[p++]=mat[row][l];
            if(++l>r)
                break;
        }
        return res;
    }
};