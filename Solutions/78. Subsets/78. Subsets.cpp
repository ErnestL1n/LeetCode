class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        foo(nums,res,tmp,0);
        return res;
    }
    void foo(vector<int>& nums,vector<vector<int>>& res,vector<int>& tmp,int begin){
        res.push_back(tmp);
        for(int i=begin;i<nums.size();++i){
            tmp.push_back(nums[i]);
            foo(nums,res,tmp,i+1);
            tmp.pop_back();
        }
    }
};