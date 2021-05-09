class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        // 1950~2050  => 0~100
        int res=0;
        int cnt[101]={};
        for(const auto& l:logs)
            for(int i=l[0]-1950;i<l[1]-1950;++i)
               ++cnt[i];
        for(int i=0;i<101;++i)
            if(cnt[i]>cnt[res])
                res=i;
        return res+1950;
    }
};