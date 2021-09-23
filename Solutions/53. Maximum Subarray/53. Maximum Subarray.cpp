// O(N^3) BF ,TLE
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res=INT_MIN;
        for(int i=0;i<nums.size();++i)
            for(int j=i;j<nums.size();++j){
                int sum=0;
                for(int k=i;k<=j;++k)
                    sum+=nums[k];
                res=max(res,sum);
            }
        return res;
    }
};

// O(N^2) prefix sum ,TLE
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size(),res=INT_MIN;
        if(n==1)
            return nums[0];
        vector<int> prefix(n+1);
        for(int i=0;i<n;++i)
            prefix[i+1]=prefix[i]+nums[i];
        for(int i=0;i<=n;++i)
            cout <<prefix[i] <<" ";
        for(int i=0;i<n;++i)
            for(int j=i;j<n;++j)
                res=max(prefix[j+1]-prefix[i],res);
        return res;
    }
};



//2021.9.22 DP
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size(),res=INT_MIN;
        //dp[i]=maximum subarray(1~i)
        //dp[i]=dp[i-1]>0?dp[i-1]+nums[i]:nums[i]
        vector<int> dp(n+1);
        for(int i=1;i<=n;++i){
            dp[i]=dp[i-1]>0?dp[i-1]+nums[i-1]:nums[i-1];
            res=max(res,dp[i]);
        }
        return res;
    }
};

//space opt
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int prev=0,cur=0,res=INT_MIN;
        for(int i=0;i<n;++i){
            cur=prev>0?prev+nums[i]:nums[i];
            res=max(res,cur);
            prev=cur;
        }
        return res; 
    }
};