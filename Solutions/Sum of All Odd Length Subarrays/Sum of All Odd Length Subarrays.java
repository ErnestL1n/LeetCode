//tricky version
class Solution {
    public int sumOddLengthSubarrays(int[] arr) {
        int res=0,n=arr.length;
        for(int i=0;i<n;++i){
            res+=((i+1)*(n-i)+1)/2*arr[i];
        }
        return res;
    }
}

//prefix sum
class Solution {
    public int sumOddLengthSubarrays(int[] arr) {
        int res=0,n=arr.length;
        int[] prefix=new int[n+1];
        for(int i=0;i<n;++i)
            prefix[i+1]=prefix[i]+arr[i];
        for(int i=0;i<n;++i)
            for(int j=i+1;j<=n;j+=2)
                res+=prefix[j]-prefix[i];
        return res;
    }
}