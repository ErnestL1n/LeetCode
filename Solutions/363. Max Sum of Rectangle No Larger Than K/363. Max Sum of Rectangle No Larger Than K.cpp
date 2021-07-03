class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& mat, int k) {
        if(mat.size()==0)
            return 0;
        int row=mat.size(),col=mat[0].size(),res=INT_MIN;
        for(int l=0;l<col;++l){
            vector<int> sums(row);
            for(int r=l;r<col;++r){
                for(int i=0;i<row;++i)
                    sums[i]+=mat[i][r];
                set<int> s;
                s.insert(0);
                int cursum=0,curmax=INT_MIN;
                for(const auto& sum:sums){
                    cursum+=sum;
                    auto it=s.lower_bound(cursum-k);
                    if(it!=s.end())
                        curmax=max(curmax,cursum-*it);
                    s.insert(cursum);
                }
                res=max(res,curmax);
            }
        }
        return res;
    }
};