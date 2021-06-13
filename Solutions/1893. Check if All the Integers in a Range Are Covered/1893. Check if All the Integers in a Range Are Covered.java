class Solution {
    public boolean isCovered(int[][] ranges, int left, int right) {
        int[] cnt=new int[51];
        for(var r:ranges)
            for(int x=r[0];x<=r[1];++x)
                cnt[x]=1;
        for(int i=left;i<=right;++i)
            if(cnt[i]==0)
                return false;
        return true;
    }
}