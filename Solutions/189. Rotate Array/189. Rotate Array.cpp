// nums = "----->-->"; k =3
// result = "-->----->";

// reverse "----->-->" we can get "<--<-----"
// reverse "<--" we can get "--><-----"
// reverse "<-----" we can get "-->----->"

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k%=n;
        reverse(nums,0,n-1);
        reverse(nums,0,k-1);
        reverse(nums,k,n-1);
    }
    void reverse(vector<int>& nums,int lo,int hi){
        while(lo<hi){
            int tmp=nums[hi];
            nums[hi]=nums[lo];
            nums[lo]=tmp;
            ++lo,--hi;
        }
    }
};