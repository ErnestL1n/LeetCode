class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if(nums.size()<=1){
            if(nums.size()==0){
                return res;
            }
            res.push_back(to_string(nums[0]));
            return res;
        }
        for(int i=0;i<nums.size();++i){
            int st=i,ed=i;
            while(i!=nums.size()-1 and nums[i]+1==nums[i+1]){
                ed=i+1;
                ++i;
            }
            if(st!=ed){
                res.push_back(to_string(nums[st])+"->"+to_string(nums[ed]));
            }else{
                res.push_back(to_string(nums[st]));
            }
        }
        return res;
    }
};