class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> tmp;
        for(int i=0;i<nums.size();++i){
            if(i==0 or nums[i]!=nums[i-1]){
                tmp.push_back(nums[i]);
            }
        }
        int res=0;
        for(int i=1;i<tmp.size()-1;++i){
            if((tmp[i-1]<tmp[i] and tmp[i]>tmp[i+1]) or (tmp[i-1]>tmp[i] and tmp[i]<tmp[i+1])){
                ++res;
            }
        }
        return res;
    }
};