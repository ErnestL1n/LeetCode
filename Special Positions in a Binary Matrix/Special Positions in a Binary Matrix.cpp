/* HashMap
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int row=mat.size(),col=mat[0].size();
        unordered_map<int,int> rows,cols;
        for(int i=0;i<row;++i)
            for(int j=0;j<col;++j){
                if(mat[i][j])
                    ++rows[i],++cols[j];
            }
        int res=0;
        for(int i=0;i<row;++i)
            for(int j=0;j<col;++j){
                if(mat[i][j]&&rows[i]==1&&cols[j]==1)
                    ++res;
            }
        return res;
    }
};
*/

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int row=mat.size(),col=mat[0].size();
        vector<int> rows(row),cols(col);
        for(int i=0;i<row;++i)
            for(int j=0;j<col;++j){
                if(mat[i][j])
                    ++rows[i],++cols[j];
            }
        int res=0;
        for(int i=0;i<row;++i)
            for(int j=0;j<col;++j){
                if(mat[i][j]&&rows[i]==1&&cols[j]==1)
                    ++res;
            }
        return res;
    }
};
