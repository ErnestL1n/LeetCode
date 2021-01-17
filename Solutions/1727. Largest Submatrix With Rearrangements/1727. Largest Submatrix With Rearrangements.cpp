class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int res=0;
        for(int i=1;i<matrix.size();++i)
            for(int j=0;j<matrix[0].size();++j)
                if(matrix[i][j])
                    matrix[i][j]+=matrix[i-1][j];
        for(int row=0;row<matrix.size();++row){
            sort(begin(matrix[row]),end(matrix[row]),greater());
            for(int col=0;col<matrix[0].size();++col)
                res=max(res,matrix[row][col]*(col+1));
        }
        return res;
    }
};


// update , or copy into new vector
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int res=0;
        for(int i=0;i<matrix.size();++i){
            for(int j=0;j<matrix[0].size();++j){
                if(i>0&&matrix[i][j]!=0)
                    matrix[i][j]=matrix[i-1][j]+1;
            }
            vector<int> foo;
            foo=matrix[i];
            sort(begin(foo),end(foo),greater<int>());
            for(int col=0;col<matrix[0].size();++col)
                res=max(res,(col+1)*foo[col]);
        }
        return res;
    }
};