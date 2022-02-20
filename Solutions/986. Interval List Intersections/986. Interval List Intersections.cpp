class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& a, vector<vector<int>>& b) {
        vector<vector<int>> res;
        for(int i=0,j=0;i<a.size() and j<b.size();a[i][1]<b[j][1]?++i:++j){
            int st=max(a[i][0],b[j][0]);
            int ed=min(a[i][1],b[j][1]);
            if(st<=ed){
                res.push_back({st,ed});
            }
        }
        return res;
    }
};