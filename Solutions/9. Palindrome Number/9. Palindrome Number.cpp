class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 or (x!=0 and x%10==0))
            return false;
        int half=0;
        while(x>half){
            half=half*10+x%10;
            x/=10;
        }
        return half==x or half/10==x;
    }
};

// int to string method
class Solution {
public:
    bool isPalindrome(int x) {
        string s=to_string(x);
        for(int i=0,j=s.size()-1;i<=j;++i,--j)
            if(s[i]!=s[j])
                return false;
        return true;
    }
};