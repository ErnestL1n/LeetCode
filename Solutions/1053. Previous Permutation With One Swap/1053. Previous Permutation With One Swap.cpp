class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n=arr.size(),idx=-1;
        if(n<=1)
            return arr;
        for(int i=n-1;i>0;--i){
            if(arr[i]<arr[i-1]){
                idx=i-1;
                break;
            }
        }
        if(idx==-1)
            return arr;
        for(int i=n-1;i>idx;--i){
            if(arr[idx]>arr[i] and arr[i]!=arr[i-1]){
                swap(arr[i],arr[idx]);
                break;
            }
        }
        return arr;
    }
};