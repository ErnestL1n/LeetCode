class Solution {
    public int[] diStringMatch(String S) {
        int[] res=new int[S.length()+1];
        for(int i=0,l=0,h=S.length();i<=S.length();++i)
            res[i]=i==S.length()||S.charAt(i)=='I'?l++:h--;
        return res;
    }
}