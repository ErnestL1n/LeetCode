class Solution {
public:
    vector<int> nums;
    
    Solution(vector<int>& nums) {
        this->nums=nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res(nums);
        for(int i=0;i<nums.size();++i){
            // c++ random number min~max => rand()%(max-min)+min
            int pos=rand()%(nums.size()-i)+i;
            swap(res[i],res[pos]);
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */