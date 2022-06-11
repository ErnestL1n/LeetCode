class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target=-x;
        for (auto& num:nums){
            target+=num;
        }
        if(target==0){
            return nums.size();
        }
        unordered_map<int,int> m;
        m[0]=-1;
        int sum=0;
        int res=INT_MIN;

        for(int i=0;i<nums.size();++i){
            sum+=nums[i];
            if(m.count(sum-target)) {
                res=max(res,i-m[sum-target]);
            }
            m[sum]=i;
        }
        return res==INT_MIN?-1:nums.size()-res;
    }
};