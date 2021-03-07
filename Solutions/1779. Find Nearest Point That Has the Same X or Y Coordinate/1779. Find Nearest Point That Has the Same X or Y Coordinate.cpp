class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& p) {
        int res=-1,dist=INT_MAX;
        for(int i=0;i<p.size();++i){
            if(p[i][0]==x||p[i][1]==y){
                int mh=abs(p[i][0]-x)+abs(p[i][1]-y);
                if(mh<dist){
                    dist=mh;
                    res=i;
                }
            }
        }
        return res;
    }
};