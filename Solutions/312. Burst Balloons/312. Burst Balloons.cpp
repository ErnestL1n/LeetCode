//buttom up method
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> arr;
        for(int num:nums)
            if(num>0)
                arr.push_back(num);
        arr.insert(arr.begin(),1);
        arr.insert(arr.end(),1);
        int size=arr.size();
        vector<vector<int>> dp(size,vector<int>(size,0));
        for(int i=size-1;i>=0;--i)
            for(int j=i+1;j<size;++j)
                for(int k=i+1;k<j;++k)
                    dp[i][j]=max(dp[i][j],
                                dp[i][k]+dp[k][j]+arr[i]*arr[k]*arr[j]);
        return dp[0][size-1];
    }
};
/*******************************************************************************/
//top down recursive method with memoization
class Solution {
public:
    int dp[502][502];
    int maxCoins(vector<int>& nums) {
        vector<int> arr;
        for(int num:nums)
            if(num>0)
                arr.push_back(num);
        arr.insert(arr.begin(),1);
        arr.insert(arr.end(),1);
        return help(arr,0,arr.size()-1);
    }
    int help(vector<int>& arr,int i,int j){
        if(j-i==1)
            return 0;
        if(!dp[i][j]){
            for(auto k=i+1;k<j;++k)
                dp[i][j]=max(dp[i][j],
                            arr[i]*arr[k]*arr[j]+help(arr,i,k)+help(arr,k,j));
        }
        return dp[i][j];
    }
};






//2021.9.22
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.insert(nums.end(),1);
        vector<vector<int>> dp(n+2,vector<int>(n+2));
        for(int l=1;l<=n;++l){
            for(int i=1;i<=n-l+1;++i){
                int j=i+l-1;
                for(int k=i;k<=j;++k)
                    dp[i][j]=max(dp[i][j],dp[i][k-1]+dp[k+1][j]+nums[i-1]*nums[k]*nums[j+1]);
            }
        }
        return dp[1][n];
    }
};