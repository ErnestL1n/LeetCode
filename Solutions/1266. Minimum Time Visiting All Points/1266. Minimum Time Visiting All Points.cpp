class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res=0;
        for(int i=1;i<points.size();++i){
            auto curr=points[i-1],next=points[i];
            res+=max(abs(curr[0]-next[0]),abs(curr[1]-next[1]));
        }
        return res;
    }
};