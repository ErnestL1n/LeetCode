//std::make_heap
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        make_heap(begin(nums),end(nums));
        while(--k){
            pop_heap(begin(nums),end(nums));
            nums.pop_back();
        }
        pop_heap(begin(nums),end(nums));
        return nums.back();
    }
};


//priority_queue
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(begin(nums),end(nums));
        while(--k)
            pq.pop();
        return pq.top();
    }
};