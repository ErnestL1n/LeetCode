//recursive
//idea:https://leetcode.wang/leetCode-46-Permutations.html
//input:[1,2,3]

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        help(0,nums,result);
        return result;
    }
    void help(int begin,vector<int>& nums,vector<vector<int>>& result){
        if(begin==nums.size()){
            result.push_back(nums);
            return;
        }
		//output:[[3,1,2],[3,2,1],[2,3,1],[2,1,3],[1,3,2],[1,2,3]]
        for(int i=nums.size()-1;i>=begin;--i){
            swap(nums[i],nums[begin]);
            help(begin+1,nums,result);
            swap(nums[i],nums[begin]);
        }
        return;
    }
};


//output reversed
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        help(0,nums,res);
        return res;
    }
    void help(int begin,vector<int>& nums,vector<vector<int>>& res){
        if(begin==nums.size())
        {
            res.push_back(nums);
            return;
        }
		//output:[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,2,1],[3,1,2]]
        for(int i=begin;i<nums.size();++i){
            swap(nums[begin],nums[i]);
            help(begin+1,nums,res);
            swap(nums[begin],nums[i]);
        }
        return;
    }
};


// 2022.2.13
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(res,tmp,nums);
        return res;
    }
    void dfs(vector<vector<int>>& res,vector<int>& tmp,vector<int>& nums){
        if(tmp.size()==nums.size()){
            res.push_back(tmp);
            return;
        }
        for(int i=0;i<nums.size();++i){
            if(find(tmp.begin(),tmp.end(),nums[i])!=tmp.end()){
                continue;
            }
            tmp.push_back(nums[i]);
            dfs(res,tmp,nums);
            tmp.pop_back();
        }
    }
};



