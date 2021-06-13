class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        int cnt[51]={};
        for(const auto& r:ranges)
            for(int x=r[0];x<=r[1];++x)
                cnt[x]=1;
        for(int i=left;i<=right;++i)
            if(cnt[i]==0)
                return false;
        return true;
    }
};