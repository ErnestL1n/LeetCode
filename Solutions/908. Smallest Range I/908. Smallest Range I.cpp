class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int m_ax=*max_element(begin(nums),end(nums)),m_in=*min_element(begin(nums),end(nums));
        return (m_ax-m_in-2*k>0)?m_ax-m_in-2*k:0;
    }
};