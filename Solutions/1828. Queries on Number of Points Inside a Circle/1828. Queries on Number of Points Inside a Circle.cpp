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

//optimize version
class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& ps, vector<vector<int>>& queries) {
        vector<int> res;
        vector<array<int, 2>> sp;
        for (auto &p : ps)
            sp.push_back({p[0], p[1]});
        sort(begin(sp), end(sp));
        for (auto &q : queries) {
            int cnt = 0, rr = q[2] * q[2];
            auto it = lower_bound(begin(sp), end(sp), array<int, 2>{q[0] - q[2], 0});
            for (; it != end(sp) && (*it)[0] <= q[0] + q[2]; ++it)
                cnt += (q[0] - (*it)[0]) * (q[0] - (*it)[0]) + (q[1] - (*it)[1]) * (q[1] - (*it)[1]) <= rr;
            res.push_back(cnt);
        }
        return res;
    }
};