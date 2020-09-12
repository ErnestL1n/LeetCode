class Solution {
    public int numTriplets(int[] nums1, int[] nums2) {
        return (int)(count(nums1,nums2)+count(nums2,nums1));
    }
    private long count(int[] nums1,int[] nums2){
        long res=0;
        HashMap<Long,Long> map=new HashMap<>();
        for(long n2:nums2){
            long tmp=map.getOrDefault(n2,0l);
            ++tmp;
            map.put(n2,tmp);
        }
        for(long n1:nums1){
            long target=n1*n1;
            for(var entry:map.entrySet()){
                long key=entry.getKey();
                long value=entry.getValue();
                if(target%key!=0||!map.containsKey(target/key))
                    continue;
                if(target/key==key)
                    res+=value*(value-1);
                else
                    res+=value*map.get(target/key);
            }
        }
        return res/2;
    }
}