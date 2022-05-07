class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int z=INT_MIN;
        stack<int> stk;
        for(int i=nums.size()-1;i>=0;--i){
            if(nums[i]<z){
                return true;
            }else{
                while(stk.size() and nums[i]>stk.top()){
                    z=stk.top();stk.pop();
                }
                stk.push(nums[i]);
            }
        }
        return false;
    }
};