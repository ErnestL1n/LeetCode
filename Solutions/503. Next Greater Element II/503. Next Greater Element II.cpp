class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> stk,res(n,-1);
        for(int i=0;i<n*2;++i){
            while(stk.size()&&nums[stk.back()]<nums[i%n]){
                res[stk.back()]=nums[i%n];
                stk.pop_back();
            }
            stk.push_back(i%n);
        }
        return res;
    }
};