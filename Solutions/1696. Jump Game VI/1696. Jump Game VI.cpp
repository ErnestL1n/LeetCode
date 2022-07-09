class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        long cur=0;
        deque<int> q;
        for(int i=nums.size()-1;i>=0;--i){
            cur=nums[i]+(q.size()?nums[q.front()]:0);
            while(q.size() and cur>nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
            if(q.front()>=i+k){
                q.pop_front();
            }
            nums[i]=cur;
        }
        return cur;
    }
};