class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int res=INT_MAX;
        int cnt[26]={};
        for(const auto& c:text)
            if(c=='a' or c=='b' or c=='l' or c=='o' or c=='n')
                ++cnt[c-'a'];
        cnt['l'-'a']/=2;
        cnt['o'-'a']/=2;
        for(int i=0;i<26;++i)
            if(i=='a'-'a' or i=='b'-'a' or i=='l'-'a' or i=='o'-'a' or i=='n'-'a')
                res=min(res,cnt[i]);
        return res;
    }
};