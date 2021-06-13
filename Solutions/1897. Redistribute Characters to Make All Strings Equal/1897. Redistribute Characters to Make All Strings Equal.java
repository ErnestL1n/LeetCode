class Solution {
    public boolean makeEqual(String[] words) {
        int[] cnt=new int[26];
        for(var w:words)
            for(var c:w.toCharArray())
                ++cnt[c-'a'];
        for(var x:cnt)
            if(x%words.length!=0)
                return false;
        return true;
    }
}