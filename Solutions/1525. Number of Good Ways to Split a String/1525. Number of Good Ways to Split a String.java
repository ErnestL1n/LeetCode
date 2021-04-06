class Solution {
    public int numSplits(String s) {
        int[] l=new int[26],r=new int[26];
        int d_l=0,d_r=0,res=0;
        for(var ch:s.toCharArray())
            d_r+=++r[ch-'a']==1?1:0;
        for(var ch:s.toCharArray()){
            d_l+=++l[ch-'a']==1?1:0;
            d_r-=--r[ch-'a']==0?1:0;
            res+=d_l==d_r?1:0;
        }
        return res;
    }
}