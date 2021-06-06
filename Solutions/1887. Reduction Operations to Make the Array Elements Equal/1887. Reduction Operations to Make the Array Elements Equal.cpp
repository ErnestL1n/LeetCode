class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int res=0;
        sort(nums.begin(),nums.end(),greater());
        int curr=nums[0],cnt=0;
        for(int i=1;i<nums.size();++i){
            ++cnt;
            if(nums[i]!=curr){
                res+=cnt;
                curr=nums[i];
                continue;
            }else
                continue;
        }
        return res;
    }
};

//clear version
//We sort the array, and go right-to-left, from largest to smallest.
//If the current number is the same as the one before it, we do nothing. 
//If the number before is different, we need to update all numbers on the right (sz - j).
class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int res=0,sz=nums.size();
        for(int i=sz-1;i>0;--i)
            if(nums[i]!=nums[i-1])
                res+=sz-i;
        return res;
    }
};