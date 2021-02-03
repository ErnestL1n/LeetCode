class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        int[] cnt=new int[1001];
        for(int i=0;i<arr1.length;++i)
            ++cnt[arr1[i]];
        int i=0;
        for(var n:arr2)
            while(cnt[n]-->0)
                arr1[i++]=n;
        for(int n=0;n<=1000;++n)
            while(cnt[n]-->0)
                arr1[i++]=n;
        return arr1;
    }
}