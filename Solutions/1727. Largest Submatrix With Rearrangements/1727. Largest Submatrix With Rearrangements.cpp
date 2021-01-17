class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& m) {
        int res=0;
        for(int row=0;row<m.size();++row){
            for(int col=0;col<m[0].size();++col){
                if(m[row][col]&&row>0)
                    m[row][col]+=m[row-1][col];  
            }
        }
        sort(m[m.size()-1].begin(),m[m.size()-1].end(),greater());
        for(int j=0;j<m[0].size();++j){
            res=max(res,(j+1)*m[m.size()-1][j]);
        }
        return res;
    }
};