class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        int zcnt,ocnt;
        for(auto& s:strs){
            zcnt=ocnt=0;
            for(auto& c:s){
                if(c=='0'){
                    ++zcnt;
                }else{
                    ++ocnt;
                }
            }
            for(int i=m;i>=zcnt;--i){
                for(int j=n;j>=ocnt;--j){
                    dp[i][j]=max(dp[i][j],1+dp[i-zcnt][j-ocnt]);
                }
            }
        }
        return dp[m][n];
    }
};