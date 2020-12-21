class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int res=0,tmp=0,i=0,j=0;
        unordered_set<int> s;
        while(i<nums.size()&&j<nums.size()){
            if(s.find(nums[i])==s.end()){
                s.insert(nums[i]);
                tmp+=nums[i++];
                res=max(tmp,res);
            }else{
                s.erase(nums[j]);
                tmp-=nums[j++];
            }
        }
        return res;
    }
};