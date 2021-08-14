class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int n=boxes.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(n)));
        for(int j=0;j<n;++j)
            for(int k=0;k<=j;++k)
                dp[j][j][k]=(k+1)*(k+1);
        for(int l=1;l<n;++l){
            for(int j=l;j<n;++j){
                int i=j-l;
                for(int k=0;k<=i;++k){
                    int res=(k+1)*(k+1)+dp[i+1][j][0];
                    for(int m=i+1;m<=j;++m) {
    	                if(boxes[m]==boxes[i]) 
    	                    res=max(res,dp[i+1][m-1][0]+dp[m][j][k+1]);
    	            }
                    dp[i][j][k] = res;
                }
            }
        }
        return (n==0?0:dp[0][n-1][0]);
    }
};