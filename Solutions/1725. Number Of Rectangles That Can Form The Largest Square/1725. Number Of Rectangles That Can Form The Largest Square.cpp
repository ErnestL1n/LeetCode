class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rec) {
        int res=0,mx=0;
        for(auto& r:rec){
            int x=min(r[0],r[1]);
            if(x>mx){
                res=1;
                mx=x;
            }else if(x==mx)
                ++res;
        }
        return res;
    }
};