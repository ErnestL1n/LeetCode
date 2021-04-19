class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> res;
        for(auto& q:queries){
            int cnt=0;
            for(auto& p:points){
                if(foo(q[0],q[1],q[2],p[0],p[1]))
                    ++cnt;
            }
            res.push_back(cnt);
        }
        return res;
    }
    bool foo(int cx,int cy,int r,int x,int y){
        if((x-cx)*(x-cx)+(y-cy)*(y-cy)<=r*r)
            return true;
        return false;
    }
};