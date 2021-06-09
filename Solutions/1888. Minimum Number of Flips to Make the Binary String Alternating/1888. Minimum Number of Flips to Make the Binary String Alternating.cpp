class Solution {
public:
    int minFlips(string s) {
        // 111000111000
        // |....| = 111000
        //  |....| = 110001
        //   |....| = 100011
        //    |....| = 000111
        //     |....| = 001110
        //      |....| = 011100
        // 111000 110001 100011 000111 001110 011100
        int n=s.size();
        s+=s;
        string s1,s2;
        int cnt1=0,cnt2=0,res=INT_MAX;
        for(int i=0;i<2*n;++i){
            s1+=i%2==0?'0':'1';
            s2+=i%2==0?'1':'0';
        }
        for(int i=0;i<2*n;++i){
            if(s1[i]!=s[i])++cnt1;
            if(s2[i]!=s[i])++cnt2;
            if(i>=n){
                if(s1[i-n]!=s[i-n])--cnt1;
                if(s2[i-n]!=s[i-n])--cnt2;
            }
            if(i>=n-1)
                res=min({res,cnt1,cnt2});
        }
        return res;
    }
};