class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int n=heights.size(),res=0;
        stack<int> idx;
        for(int i=0;i<n;++i){
            while(idx.size() and heights[idx.top()]>heights[i]){
                int h=heights[idx.top()];idx.pop();
                int l=idx.size()?idx.top():-1;
                res=max(res,h*(i-l-1));
            }
            idx.push(i);
        }
        return res;
    }
};