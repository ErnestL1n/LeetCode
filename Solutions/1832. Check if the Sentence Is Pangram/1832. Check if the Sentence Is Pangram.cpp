class Solution {
public:
    bool checkIfPangram(string s) {
        int cnt[26]={};
        for(const auto& c:s)
            ++cnt[c-'a'];
        for(int i=0;i<26;++i)
            if(cnt[i]<1)
                return false;
        return true;
    }
};