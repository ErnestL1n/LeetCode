//Intutive
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res;
        for(int i=0,res=nums.size();i<nums.size();++i)
            res+=i-nums[i];
        return res;
    }
};

//Bit Manipulation
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i,res;
        for(i=0,res=nums.size();i<nums.size();++i)
            res^=i^nums[i];
        return res;
    }
};