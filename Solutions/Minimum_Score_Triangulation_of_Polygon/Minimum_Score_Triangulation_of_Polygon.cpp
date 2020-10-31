class Solution {
public:
    int dpTopDown[50][50];
    int minScoreTriangulationTopDown(vector<int>& A) {
        return help(A,0,A.size()-1);
    }
    int help(vector<int>& arr,int i,int j){
        if(j-i<=1)return 0;
        if(!dpTopDown[i][j]){
            dpTopDown[i][j]=INT_MAX;
            for(int k=i+1;k<j;++k)
            dpTopDown[i][j]=min(dpTopDown[i][j],help(arr,i,k)+help(arr,k,j)+arr[i]*arr[k]*arr[j]);
        }
        return dpTopDown[i][j];
    }
	int minScoreTriangulationBottomUp(vector<int>& A) {
		vector<vector<int>> dp(50,vector<int>(50));
        for(int i=A.size()-1;i>=0;--i)
            for(int j=i+1;j<A.size();++j)
                for(int k=i+1;k<j;++k)
                    dp[i][j]=min(dp[i][j]==0?INT_MAX:dp[i][j],
                                dp[i][k]+dp[k][j]+A[i]*A[k]*A[j]);
        return dp[0][A.size()-1];
    }
};