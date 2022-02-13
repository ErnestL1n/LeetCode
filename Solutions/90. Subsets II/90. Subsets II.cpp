class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        sort(nums.begin(),nums.end());
        dfs(res,tmp,nums,0);
        return res;
    }
    void dfs(vector<vector<int>>& res,vector<int>& tmp,vector<int>& nums,int st){
        res.push_back(tmp);
        for(int i=st;i<nums.size();++i){
            if(i>st and nums[i]==nums[i-1]){
                continue;
            }
            tmp.push_back(nums[i]);
            dfs(res,tmp,nums,i+1);
            tmp.pop_back();
        }
    }
};

//iterative solution
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res={{}};
        for(int i=0,n=0;i<nums.size();++i){
            int st=i!=0 and nums[i]==nums[i-1]?n:0;
            n=res.size();
            for(;st<n;++st){
                res.push_back(res[st]);
                res.back().push_back(nums[i]);
            }
        }
        return res;
    }
};