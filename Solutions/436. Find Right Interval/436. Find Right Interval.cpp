class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& its) {
        int n=its.size();
        map<int,int> m;
        vector<int> res(n);
        for(int i=0;i<n;++i)
            m[its[i][0]]=i;
        for(int i=0;i<n;++i)
            res[i]=m.lower_bound(its[i][1])==m.end()?-1:m.lower_bound(its[i][1])->second;
        return res;
    }
};