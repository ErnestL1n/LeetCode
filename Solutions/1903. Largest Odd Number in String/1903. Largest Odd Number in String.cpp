//TLE
class Solution {
public:
    string largestOddNumber(string s){
        int n=s.size();
        for(int i=n-1;i>=0;--i){
            if((s[i]-'0')%2==0)
                s=s.substr(0,i);
            else
                break;
        }
        return s;
    }
};