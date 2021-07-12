class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int cnt1[127]={0},cnt2[127]={0};
        for(int i=0;i<s.size();++i){
            if(cnt1[s[i]]!=cnt2[t[i]])
                return false;
            cnt1[s[i]]=i+1;
            cnt2[t[i]]=i+1;
        }
        return true;
    }
};