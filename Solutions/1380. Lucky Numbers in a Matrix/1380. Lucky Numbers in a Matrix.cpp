class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        int maxMin=INT_MIN;
        for(int i=0;i<m;++i){
            int Min=INT_MAX;
            for(int j=0;j<n;++j)
                Min=min(Min,mat[i][j]);
            maxMin=max(maxMin,Min);
        }
        int minMax=INT_MAX;
        for(int j=0;j<n;++j){
            int Max=INT_MIN;
            for(int i=0;i<m;++i)
                Max=max(Max,mat[i][j]);
            minMax=min(minMax,Max);
        }
        if(minMax!=maxMin)
            return vector<int> {};
        return vector<int> {maxMin};
    }
};