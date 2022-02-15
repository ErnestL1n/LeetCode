class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int r=*max_element(nums.begin(),nums.end());
        vector<int> arr(r+1);
        for(auto& n:nums){
            arr[n]+=n;
        }
        return rob(arr);
    }
    int rob(vector<int>& arr){
        int n=arr.size();
        vector<int> dp(n);
        dp[0]=arr[0],dp[1]=max(arr[0],arr[1]);
        for(int i=2;i<n;++i){
            dp[i]=max(dp[i-1],dp[i-2]+arr[i]);
        }
        return dp[n-1];
    }
};