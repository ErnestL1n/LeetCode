//O(NlogN)
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        return nums[n-1]*nums[n-2]-nums[0]*nums[1];
    }
};

//O(N)
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int max1=INT_MIN,max2=INT_MIN;
        int min1=INT_MAX,min2=INT_MAX;
        for(const auto& n:nums){
            if(n>=max1){
                max2=max1;
                max1=n;
            }else if(n>=max2){
                max2=n;
            }
            if(n<=min1){
                min2=min1;
                min1=n;
            }else if(n<=min2){
                min2=n;
            }
        }
        return max1*max2-min1*min2;
    }
};