class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()<=2)
            return nums.size()==1?nums[0]:nums[1]>nums[0]?nums[1]:nums[0];
        int f1=0,s1=0,f2=0,s2=0;
        for(int i=0;i<nums.size()-1;++i){
            int tmp=f1;
            f1=max(f1,s1+nums[i]);
            s1=tmp;
        }
        for(int i=1;i<nums.size();++i){
            int tmp=f2;
            f2=max(f2,s2+nums[i]);
            s2=tmp;
        }
        return f1>f2?f1:f2;
    }
};