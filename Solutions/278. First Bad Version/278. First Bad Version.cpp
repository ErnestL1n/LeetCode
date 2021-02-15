// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        unsigned lo=1,hi=n;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(isBadVersion(mid))
                hi=mid-1;
            else
                lo=mid+1;
        }
        return lo;
    }
};
