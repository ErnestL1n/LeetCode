class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        vector<int> row(m),col(n);
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)
                if(mat[i][j]==1)
                    ++row[i],++col[j];
        int res=0;
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)
                if(mat[i][j]==1 && row[i]==1 && col[j]==1)
                    ++res;
        return res;
    }
};