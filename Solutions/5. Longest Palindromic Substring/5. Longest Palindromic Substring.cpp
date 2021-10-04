// AC O(N^3) 
// TLE if not take string as reference
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        string res="";
        for(int i=0;i<n;++i){
            for(int j=i;j<n;++j){
                if(j-i+1>res.size() and isPal(s,i,j))
                    res=s.substr(i,j-i+1);
            }
        }
        return res;
    }
    bool isPal(string& s,int i,int j){
        for(;i<j;++i,--j){
            if(s[i]!=s[j])
                return false;
        }
        return true;
    }
};

// AC O(N^2)
// DP 
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size(),len=0,start;
        auto getlen=[&](int i,int j){
            while(i>=0 and j<n and s[i]==s[j])
                --i,++j;
            return j-i-1;
        };
        int center=0;
        for(;center<n;++center){
            int cur=max(getlen(center,center),
                       getlen(center,center+1));
            if(cur>len){
                len=cur;
                start=center-(len-1)/2;
            }
        }
        return s.substr(start,len);
    }
};