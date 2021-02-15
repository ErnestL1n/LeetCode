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




//STL 
class Solution {
public:
    int minimumSize(vector<int>& ns, int maxOperations) {
    int l = 1, r = 1000000000;
    while (l < r) {
        int m = (l + r) / 2;
        if (accumulate(begin(ns), end(ns), 0, [&](int s, int n){ return s + (n - 1) / m; }) <= maxOperations)
            r = m;
        else
            l = m + 1;
    }
    return l;
}
};