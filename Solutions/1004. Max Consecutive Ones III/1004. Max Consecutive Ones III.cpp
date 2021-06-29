class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0;
        for(;j<nums.size();++j){
            if(nums[j]==0)
                --k;
            if(k<0){
                if(nums[i]==0){
                    ++k;
                }
                ++i;
            }
        }
        return j-i;
    }
};

//clear version
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0;
        for(;j<nums.size();++j){
            if(nums[j]==0)
                --k;
            if(k<0 and nums[i++]==0)
                ++k;
        }
        return j-i;
    }
};

//why this can't work ,see note
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0;
        while(j++<nums.size()){
            if(nums[j]==0)
                --k;
            if(k<0 and nums[i++]==0)
                ++k;
        }
        return j-i;
    }
};