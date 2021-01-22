class Solution {
public:
    int minAddToMakeValid(string s) {
        int res=0,cnt=0;
        for(int i=0;i<s.size();++i){
            if(s[i]=='(')
                ++cnt;
            if(s[i]==')')
                --cnt;
            if(s[i]==')'&&cnt<0){
                res+=abs(cnt);
                cnt=0;
            }
        }
        res+=cnt;
        return res;
    }
};