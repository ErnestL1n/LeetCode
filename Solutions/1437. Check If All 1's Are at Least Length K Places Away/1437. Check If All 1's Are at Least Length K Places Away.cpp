class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        for(int i=0,j=-1;i<nums.size();++i){
            if(nums[i]){
                if(j!=-1&&i-j-1<k)
                    return false;
                j=i;
            }
        }
        return true;
    }
};