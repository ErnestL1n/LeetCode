// O(N^2) => TLE
class Solution {
public:
    bool canJump(vector<int>& nums) {
        // dp[i] : whether we can jump to i
        // dp[i] is true <=> there exists dp[j] is true and j can jump to i
        vector<bool> dp(nums.size());
        dp[0]=true;
        for(int i=1;i<nums.size();++i){
            for(int j=0;j<i;++j){
                if(dp[j] and j+nums[j]>=i){
                    dp[i]=true;
                }
            }
        }
        return dp[nums.size()-1];
    }
};

// O(N) => AC
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int dis=0;
        for(int i=0;i<=dis;++i){
            dis=max(dis,i+nums[i]);
            if(dis>=nums.size()-1)
                return true;
        }
        return false;
    }
};