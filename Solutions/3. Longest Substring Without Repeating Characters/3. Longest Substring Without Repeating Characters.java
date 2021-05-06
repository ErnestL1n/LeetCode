class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character,Integer> m=new HashMap<>();
        int res=0;
        for(int i=0,j=0;j<s.length();++j){
            if(m.containsKey(s.charAt(j)))
                i=Math.max(i,m.get(s.charAt(j))+1);
            m.put(s.charAt(j),j);
            res=Math.max(res,j-i+1);
        }
        return res;
    }
}