class Solution {
public:
    bool validPalindrome(string s) {
        int lo=0,hi=s.size()-1;
        while(lo<hi){
            if(s[lo]!=s[hi]){
                if(isPal(s,lo+1,hi) or isPal(s,lo,hi-1)){
                    return true;
                }
                return false;
            }
            ++lo,--hi;
        }
        return true;
    }
    bool isPal(string& s,int lo,int hi){
        while(lo<hi){
            if(s[lo++]!=s[hi--]){
                return false;
            }
        }
        return true;
    }
};