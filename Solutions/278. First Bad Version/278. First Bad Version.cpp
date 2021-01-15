// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        unsigned l=0,r=n;
        while(l<=r){
            unsigned m=(l+r)/2;
            if(isBadVersion(m))
                r=m-1;
            else
                l=m+1;
        }
        return l;
    }
};