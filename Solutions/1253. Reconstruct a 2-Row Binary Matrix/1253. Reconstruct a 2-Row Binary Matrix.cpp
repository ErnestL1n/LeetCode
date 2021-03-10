class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n=colsum.size();
        vector<vector<int>> res(2,vector<int>(n));
        for(int i=0;i<n;++i){
            if(colsum[i]==2){
                --upper,--lower;
                res[0][i]=1;
                res[1][i]=1;
            }
            else if(colsum[i]==1){
                if(upper>lower){
                    res[0][i]=1; 
                    --upper;
                }
                else{
                    res[1][i]=1;
                    --lower;
                }
            }
            if(upper<0 || lower<0)
                return vector<vector<int>>{};
        }
        return upper==0&&lower==0?res:vector<vector<int>>{};
    }
};