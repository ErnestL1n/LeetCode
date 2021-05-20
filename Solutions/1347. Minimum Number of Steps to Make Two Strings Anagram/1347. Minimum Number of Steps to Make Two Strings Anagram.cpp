class Solution {
public:
    int minSteps(string s, string t) {
        int res=0;
        int cnt[26]={};
        for(const auto& c:s)
            ++cnt[c-'a'];
        for(const auto& c:t)
            --cnt[c-'a'];
        for(int i=0;i<26;++i)
            res+=cnt[i]==0?0:abs(cnt[i]);
        return res/2;
    }
};