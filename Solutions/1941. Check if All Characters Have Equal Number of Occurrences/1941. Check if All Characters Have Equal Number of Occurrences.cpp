class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int cnt[26]={};
        for(const auto& c:s)
            ++cnt[c-'a'];
        int o=-1;
        for(int i=0;i<26;++i){
            if(cnt[i]==0)
                continue;
            o=cnt[i];
            break;
        }
        for(int i=0;i<26;++i)
            if(cnt[i]!=0 and cnt[i]!=o)
                return false;
        return true;
    }
};