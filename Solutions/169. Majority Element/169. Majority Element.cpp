class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
};

//trick
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major=nums[0],cnt=1;
        for(int i=1;i<nums.size();++i){
            if(cnt==0){
                ++cnt;
                major=nums[i];
            }else if(major==nums[i]){
                ++cnt;
            }else{
                --cnt;
            }
        }
        return major;
    }
};