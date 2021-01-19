typedef vector<vector<int>> VVI;
typedef vector<int> VI;
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        VVI res;
        VI path;
        sort(begin(nums),end(nums));
        foo(res,path,nums,0);
        return res;
    }
    void foo(VVI& res,VI& path,VI& nums,int begin){
        res.push_back(path);
        for(int i=begin;i<nums.size();++i){
            if(i>begin&&nums[i]==nums[i-1])continue;
            path.push_back(nums[i]);
            foo(res,path,nums,i+1);
            path.pop_back();
        }
    }
};