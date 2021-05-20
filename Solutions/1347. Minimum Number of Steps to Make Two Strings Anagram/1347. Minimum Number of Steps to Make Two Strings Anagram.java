class Solution {
    public int minSteps(String s, String t) {
        int res=0;
        int[] cnt=new int[26];
        for(var c:s.toCharArray())
            ++cnt[c-'a'];
        for(var c:t.toCharArray())
            --cnt[c-'a'];
        for(int i=0;i<26;++i)
            res+=(cnt[i]==0)?0:Math.abs(cnt[i]);
        return res/2;
    }
}