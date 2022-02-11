class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m=s1.size(),n=s2.size();
        if(m>n){
            return false;
        }
        int cnt[26]={};
        for(int i=0;i<m;++i){
            ++cnt[s1[i]-'a'];
            --cnt[s2[i]-'a'];
        }
        if(allzero(cnt)){
            return true;
        }
        for(int i=m;i<n;++i){
            --cnt[s2[i]-'a'];
            ++cnt[s2[i-m]-'a'];
            if(allzero(cnt)){
                return true;
            }
        }
        return false;
    }
    bool allzero(int (&cnt)[26]){
        for(int i=0;i<26;++i){
            if(cnt[i]!=0){
                return false;
            }
        }
        return true;
    }
};