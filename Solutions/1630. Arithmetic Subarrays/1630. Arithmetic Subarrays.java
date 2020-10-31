class Solution {
    public List<Boolean> checkArithmeticSubarrays(int[] nums, int[] l, int[] r) {
        List<Boolean> res=new ArrayList<>();
        for(int i=0;i<l.length;++i){
            int st=l[i],ed=r[i];
            int[] temp=new int[ed-st+1];
            for(int s=0,k=st;k<=ed;++s,++k)
                temp[s]=nums[k];
            Arrays.sort(temp);
            int j=1;
            for(;j<temp.length;++j){
                if(temp[j]-temp[j-1]!=temp[1]-temp[0]){
                    res.add(false);
                    break;
                }
            }
            if(j==temp.length)
                res.add(true);
        }
        return res;
    }
}