class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> cnt(26,INT_MAX);
        for(auto s:A){
            vector<int> cnt1(26,0);
            for(auto c:s)++cnt1[c-'a'];
            for(int i=0;i<26;++i)cnt[i]=min(cnt[i],cnt1[i]);
        }
        vector<string> res;
        for(int i=0;i<26;++i)
            for(int j=0;j<cnt[i];++j)
                res.push_back(string(1,'a'+i));
        return res;
    }
};