class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int lo=1,hi=1e9;
        while(lo<=hi){
            int mid=(lo+hi)/2,cnt=0;
            for(int n:nums)
                cnt+=(n-1)/mid;
            if(cnt>maxOperations)
                lo=mid+1;
            else
                hi=mid-1;
        }
        return lo;
    }
};