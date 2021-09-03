class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        vector<vector<int>> points;
        int n=trees.size();
        // x same=> y larger first
        sort(trees.begin(),trees.end(),[](const auto& a,const auto& b){
            if(a[0]==b[0])
                return a[1]>b[1];
            else
                return a[0]<b[0];
        });
        for(int i=0;i<n;++i){
            while(points.size()>=2 and orientation(points[points.size()-2], points[points.size()-1],trees[i])>0)
                points.pop_back();
            points.push_back(trees[i]);
        }
        points.pop_back();
        for(int i=n-1;i>=0;--i){
            while(points.size()>=2 and orientation(points[points.size()-2], points[points.size()-1],trees[i])>0)
                points.pop_back();
            points.push_back(trees[i]);
        }
        sort(points.begin(),points.end());
        vector<vector<int>> res;
        for(const auto& p:points){
            if(res.size()>0 and p==res.back())
                continue;
            res.push_back(p);
        }
        return res;
    }
    int orientation(const vector<int>& p,const vector<int>& q,const vector<int>& r){
        return (r[1]-p[1])*(q[0]-p[0])-(q[1]-p[1])*(r[0]-p[0]);
    }
};