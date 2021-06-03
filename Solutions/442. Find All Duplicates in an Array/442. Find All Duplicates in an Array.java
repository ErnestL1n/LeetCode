class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        List<Integer> res=new ArrayList<Integer>();
        int[] cnt=new int[nums.length+1];
        for(int n:nums)
            ++cnt[n];
        for(int i=1;i<=nums.length;++i)
            if(cnt[i]==2)
                res.add(i);
        return res;
    }
}