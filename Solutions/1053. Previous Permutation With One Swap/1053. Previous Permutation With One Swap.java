class Solution {
    public int[] prevPermOpt1(int[] arr) {
        int n=arr.length,idx=-1;
        if(n<=1)
            return arr;
        for(int i=n-1;i>0;--i){
            if(arr[i]>arr[i-1]){
                idx=i-1;
                break;
            }
        }
        if(idx==-1)
            return arr;
        for(int i=n-1;i>idx;--i){
            if(arr[idx]>arr[i] && arr[i]!=arr[i-1]){
                int tmp=arr[idx];
                arr[idx]=arr[i];
                arr[i]=tmp;
                break;
            }
        }
        return arr;
    }
}