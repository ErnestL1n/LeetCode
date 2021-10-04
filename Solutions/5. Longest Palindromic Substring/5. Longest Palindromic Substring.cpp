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

