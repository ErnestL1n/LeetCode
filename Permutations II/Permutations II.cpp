class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        help(nums,result,0);
        return result;
    }
    void help(vector<int>& nums,vector<vector<int>>& result,int begin){
        if(begin==nums.size()){
            result.push_back(nums);
            return;
        }
        unordered_set<int> s;
        for(int i=begin;i<nums.size();++i){
            if(s.find(nums[i])==s.end()){
                swap(nums[begin],nums[i]);
                help(nums,result,begin+1);
                swap(nums[begin],nums[i]);
                s.insert(nums[i]);
            }
        }
        return;
    }
};