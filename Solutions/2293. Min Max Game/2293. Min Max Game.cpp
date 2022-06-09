class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        for(int n=nums.size();n>1;n-=(n/2)){
            for(int i=0;i<n/2;++i){
                if(i%2==1){
                    nums[i]=max(nums[2*i],nums[2*i+1]);
                }else{
                    nums[i]=min(nums[2*i],nums[2*i+1]);
                }
            }
        }
        return nums[0];
    }
};