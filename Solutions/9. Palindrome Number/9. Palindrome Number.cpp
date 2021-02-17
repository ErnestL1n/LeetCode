class Solution {
public:
        bool isPalindrome(int x) {
		    if (x<0 || (x!=0 && x%10==0)) return false;
		    int rev = 0;
		    while (x>rev){
		    	rev = rev*10 + x%10;
		    	x = x/10;
		    }
		    return (x==rev || x==rev/10);
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