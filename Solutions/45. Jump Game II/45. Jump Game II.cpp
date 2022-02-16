class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps=0,curend=0,curfar=0;
        for(int i=0;i<nums.size()-1;++i){
            curfar=max(curfar,nums[i]+i);
            if(i==curend){
                ++jumps;
                curend=curfar;
            }
        }
        return jumps;
    }
};