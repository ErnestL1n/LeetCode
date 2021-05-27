/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        long lo=1,hi=n;
        while(lo<=hi){
            long mid=(lo+hi)/2;
            if(isBadVersion(mid))
                hi=mid-1;
            else
                lo=mid+1;
        }
        return lo;
    }
}