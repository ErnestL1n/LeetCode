typedef vector<vector<int>> VVI;
typedef vector<int> VI;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        VVI res;
        VI tmp;
        foo(nums,res,tmp,0);
        return res;
    }
    void foo(VI& nums,VVI& res,VI& tmp,int begin){
        res.push_back(tmp);
        for(int i=begin;i<nums.size();++i){
            tmp.push_back(nums[i]);
            foo(nums,res,tmp,i+1);
            tmp.pop_back();
        }
    }
};