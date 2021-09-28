class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n=nums.size(),i=0,j=1;
        while(i<n and j<n){
            while(i<n and nums[i]%2==0)
                i+=2;
            while(j<n and nums[j]%2!=0)
                j+=2;
            if(i<n and j<n)
                swap(nums[i],nums[j]);
        }
        return nums;
    }
};