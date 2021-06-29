//multi lines
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res=-1;
        for(int i=0,j=0;j<nums.size();++j){
            if(nums[j]==1 and j!=nums.size()-1)
                continue;
            if(j==nums.size()-1 and nums[j]!=0){
                res=max(j-i+1,res);
                continue;
            }
            res=max(j-i,res);
            i=j<nums.size()-1?j+1:j;
        }
        return res;
    }
};

//simplify
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res=-1,cnt=0;
        for(const auto& n:nums)
            res=max(res,cnt=n==0?0:cnt+1);        
        return res;
    }
};