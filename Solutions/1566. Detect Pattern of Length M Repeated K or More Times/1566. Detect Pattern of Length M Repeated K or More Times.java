class Solution {
    public boolean containsPattern(int[] arr, int m, int k) {
        int cnt=0;
        for(int i=0;i+m<arr.length;++i){
            if(arr[i]!=arr[i+m])
                cnt=0;
            cnt+=(arr[i]==arr[i+m])?1:0;
            if(cnt==(k-1)*m)
                return true;
        }
        return false;
    }
}