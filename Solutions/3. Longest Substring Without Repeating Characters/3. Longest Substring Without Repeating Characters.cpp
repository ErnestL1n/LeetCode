class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res=0;
        unordered_map<char,int> m;
        for(int i=0,j=0;i<s.size();++i){
            if(m.count(s[i]))
                j=max(j,m[s[i]]);
            m[s[i]]=i+1;
            res=max(res,i-j+1);
        }
        return res;
    }
};