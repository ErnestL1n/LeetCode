class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(res,tmp,nums,0);
        return res;
    }
    void dfs(vector<vector<int>>& res,vector<int>& tmp,vector<int>& nums,int st){
        res.push_back(tmp);
        for(int i=st;i<nums.size();++i){
            tmp.push_back(nums[i]);
            dfs(res,tmp,nums,i+1);
            tmp.pop_back();
        }
    }
};

//iterative solution ,concise
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res={{}};
        for(const auto& num:nums){
            int n=res.size();
            for(int i=0;i<n;++i){
                res.push_back(res[i]);
                res.back().push_back(num);
            }
        }
        return res;
    }
};