class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || (x!=0&&x%10==0))
            return false;
        int half=0;
        while(x>half){
            half=x%10+half*10;
            x/=10;
        }
        return x==half || x==half/10;
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