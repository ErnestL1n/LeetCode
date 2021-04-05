class Solution {
public:
    int numberOfMatches(int n) {
        int res=0;
        while(n!=1){
            res+=n/2;
            if(n%2==0)
                n=n/2;
            else
                n=n/2+1;
        }
        return res;
    }
};

//trick
class Solution {
public:
    int numberOfMatches(int n) {
        return n-1;
    }
};