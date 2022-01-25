class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n=arr.size(),i=0,j=n-1;
        while(i<n-1 and arr[i+1]-arr[i]>0)
            ++i;
        while(j>0 and arr[j-1]-arr[j]>0)
            --j;
        return i==j and i>0 and j<n-1;
    }
};