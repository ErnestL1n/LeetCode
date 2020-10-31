class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        var s=new HashSet<Integer>();
        for(int i=0;i<nums1.length;++i)
            s.add(nums1[i]);
        List<Integer> l=new ArrayList<>();
        for(var i:nums2)
            if(s.remove(i)==true)
                l.add(i);
        int[] res=new int[l.size()];
        for(int i=0;i<l.size();++i)
            res[i]=l.get(i);
        return res;
    }
}