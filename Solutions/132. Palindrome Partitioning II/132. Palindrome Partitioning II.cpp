class Solution {
public:
    int minCut(string s) {
        int n=s.size();
        vector<vector<bool>> dp(n+1,vector<bool>(n+1));
        vector<int> cut(n);
        for(int i=0;i<n;++i){
            cut[i]=i;
            for(int j=0;j<=i;++j){
                if(s[i]==s[j] and (j+1>i-1 or dp[j+1][i-1])){
                    dp[j][i]=true;
                    cut[i]=j==0?0:min(cut[i],cut[j-1]+1);
                }
            }
        }
        return cut[n-1];
    }
};