class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int f=INT_MIN,s=INT_MIN;
        for(int n:nums){
            if(n>=f){
                s=f;
                f=n;
                continue;
            }
            if(n>s){
                s=n;
                continue;
            }
        }
        return (f-1)*(s-1);
    }
};


//sort
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        sort(begin(nums),end(nums));
        return (nums[n-1]-1)*(nums[n-2]-1);
    }
};