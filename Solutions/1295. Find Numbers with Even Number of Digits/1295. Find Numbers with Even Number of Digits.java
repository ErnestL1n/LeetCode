class Solution {
    public int findNumbers(int[] nums) {
        int res=0;
        for(var n:nums)
            if((10<=n && n<=99) || (1000<=n && n<=9999) || n==100000)
                ++res;
        return res;
    }
}