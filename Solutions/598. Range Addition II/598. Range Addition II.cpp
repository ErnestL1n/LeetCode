class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if(ops.size()==0)
            return m*n;
        int r_min=INT_MAX,c_min=INT_MAX;
        for(const auto& o:ops){
            r_min=min(r_min,o[0]);
            c_min=min(c_min,o[1]);
        }
        return r_min*c_min;
    }
};