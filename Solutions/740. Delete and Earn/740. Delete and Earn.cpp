class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> s(10002);
        for(int i=0;i<nums.size();++i)
            s[nums[i]]+=nums[i];
        for(int i=2;i<s.size();++i){
            s[i]=max(s[i-1],s[i-2]+s[i]);
        }
        return s[10001];
    }
};