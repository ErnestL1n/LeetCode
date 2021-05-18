//brute force
class Solution {
    public int subsetXORSum(int[] nums) {
        int res=0;
        List<List<Integer>> Allsubset=new ArrayList<>();
        List<Integer> tmp=new ArrayList<>();
        subset(nums,Allsubset,tmp,0);
        for(var s:Allsubset){
            int t=0;
            for(var n:s)
                t^=n;
            res+=t;
        }
        return res;
    }
    private void subset(int[] nums,List<List<Integer>> s,List<Integer> tmp,int begin){
        s.add(new ArrayList(tmp));
        for(int i=begin;i<nums.length;++i){
            tmp.add(nums[i]);
            subset(nums,s,tmp,i+1);
            tmp.remove(tmp.size()-1);
        }
        return;
    }
}

//trick 
class Solution {
    public int subsetXORSum(int[] nums) {
        int res=0,n=nums.length;
        for(int i=0;i<n;++i)
            res|=nums[i];
        res*=Math.pow(2,n-1);
        return res;
    }
}