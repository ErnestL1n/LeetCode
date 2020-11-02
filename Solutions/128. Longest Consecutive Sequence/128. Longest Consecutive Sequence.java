// HashSet implementation
class Solution {
    public int longestConsecutive(int[] nums) {
        Integer[] num=new Integer[nums.length];
        for(int i=0;i<num.length;++i)
            num[i]=Integer.valueOf(nums[i]);
        Set<Integer> s = new HashSet<>(Arrays.asList(num)); 
        int longseq=0;
        for(var n:s){
            if(!s.contains(n-1)){
                int currseq=0;
                while(s.contains(n++))
                    ++currseq;
                longseq=Math.max(longseq,currseq);
            }
        }
        return longseq;
    }
}


//Sort,in java this is faster than above one
class Solution {
    public int longestConsecutive(int[] nums) {
        if(nums.length==0)
            return 0;
        Arrays.sort(nums);
        int currseq=1,longseq=1;
        for(int i=1;i<nums.length;++i){
            if(nums[i]!=nums[i-1]){
                if(nums[i]==nums[i-1]+1)
                    ++currseq;
                else{
                    longseq=Math.max(currseq,longseq);
                    currseq=1;
                }
            }
        }
        return Math.max(longseq,currseq);
    }
}


//Union Find