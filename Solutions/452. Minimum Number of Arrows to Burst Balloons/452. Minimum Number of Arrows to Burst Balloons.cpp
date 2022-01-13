class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[](const vector<int>& a,const vector<int>& b){return a[1]<b[1];});
        int st=0,res=1;
        for(int i=1;i<points.size();++i){
            if(points[st][1]>=points[i][0]){
                continue;
            }
            ++res;
            st=i;
        }
        return res;
    }
};