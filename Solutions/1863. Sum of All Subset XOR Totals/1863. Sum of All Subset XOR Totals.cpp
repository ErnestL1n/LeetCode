//brute force
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int res=0;
        auto subset=Allsubset(nums);
        for(const auto& s:subset){
            int tmp=0;
            for(const auto& a:s){
                tmp^=a;
            }
            res+=tmp;
        }
        return res;
    }
    vector<vector<int>> Allsubset(vector<int>& nums){
        vector<int> tmp;
        vector<vector<int>> res;
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