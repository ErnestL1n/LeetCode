// if your solution needs to compare all N chars every time for each shift, the time complexity will be O(N^2), which will give you TLE
// TLE version
class Solution {
public:
    int minFlips(string s) {
        int n=s.size(),res=INT_MAX;
        s+=s;
        string s1,s2;
        for(int i=0;i<s.size();++i){
            if(i%2==0)
                s1+='0',s2+='1';
            else
                s1+='1',s2+='0';
        }
        int i=0,j;
        for(;i<=n;++i){
            j=i;
            int cnt=0,cnt1=0,cnt2=0;
            while(++cnt<=n){
                if(s[j]!=s1[j])
                    ++cnt1;
                if(s[j]!=s2[j])
                    ++cnt2;
                ++j;
            }
            res=min({cnt1,cnt2,res});
        }
        return res;
    }
};

//ac version
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


// space and time optimization
class Solution {
public:
    int minFlips(string s) {
        int n=s.size(),cnt1=0,cnt2=0,res=n;
        for(int i=0;i<2*n;++i){
            char c=s[i%n];
            char cc=i%2?'1':'0';
            if(c!=cc)
                ++cnt1;
            else
                ++cnt2;
            if(i>=n){
                int idx=i-n;
                cc=idx%2?'1':'0';
                if(s[idx]!=cc)
                    --cnt1;
                else
                    --cnt2;
            }
            if(i>=n-1){
                res=min({res,cnt1,cnt2});
            }
        }
        return res;
    }
};