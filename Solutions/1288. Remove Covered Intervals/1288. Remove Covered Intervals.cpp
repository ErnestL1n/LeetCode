class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // sort left ascending and right decending
        sort(begin(intervals),end(intervals),[](vector<int>& a,vector<int>& b){return a[0]!=b[0]?a[0]<b[0]:a[1]>b[1];});
        // ex: [[1,5],[1,4],[1,3],[1,2]]
        int res=0,right=0;
        for(auto& v:intervals){
            if(v[1]>right){
                ++res;
                right=v[1];
            }
        }
        return res;
    }
};