class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        sort(nums.begin(),nums.end());
        dfs(res,tmp,nums,target,0);
        return res;
    }
    void dfs(vector<vector<int>>& res,vector<int>& tmp,vector<int>& nums,int target,int st){
        if(target<0){
            return;
        }
        if(target==0){
            res.push_back(tmp);
            return;
        }
        for(int i=st;i<nums.size();++i){
            tmp.push_back(nums[i]);
            dfs(res,tmp,nums,target-nums[i],i);
            tmp.pop_back();
        }
    }
};