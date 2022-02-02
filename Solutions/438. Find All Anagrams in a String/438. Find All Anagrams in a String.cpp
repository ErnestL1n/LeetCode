class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if(s.size()<p.size()){
            return res;
        }
        vector<int> cnt(26);
        for(int i=0;i<p.size();++i){
            ++cnt[p[i]-'a'];
        }
        int i=0,j=0,sz=p.size();
        while(j<s.size()){
            if(cnt[s[j]-'a']>0){
                --sz;
            }
            --cnt[s[j]-'a'];
            ++j;
            if(sz==0){
                res.push_back(i);
            }
            if(j-i==p.size()){
                if(cnt[s[i]-'a']>=0){
                    ++sz;
                }
                ++cnt[s[i]-'a'];
                ++i;
            }
        }
        return res;
    }
};