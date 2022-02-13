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

//2022.2.13
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        vector<bool> used(nums.size());
        sort(nums.begin(),nums.end());
        dfs(res,tmp,nums,used);
        return res;
        
    }
    void dfs(vector<vector<int>>& res,vector<int>& tmp,vector<int>& nums,vector<bool>& used){
        if(tmp.size()==nums.size()){
            res.push_back(tmp);
            return;
        }
        for(int i=0;i<nums.size();++i){
            if(used[i] or (i>0 and used[i-1] and nums[i]==nums[i-1])){
                continue;
            }
            used[i]=true;
            tmp.push_back(nums[i]);
            dfs(res,tmp,nums,used);
            used[i]=false;
            tmp.pop_back();
        }
    }
};