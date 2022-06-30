class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        int cnt=0;
        while(i<j){
            cnt+=nums[j--]-nums[i++];
        }
        return cnt;
    }
};