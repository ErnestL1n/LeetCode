class Solution {
    public int lengthOfLastWord(String s) {
        s+=' ';
        List<Character> tmp=new ArrayList<>();
        for(int i=0;i<s.length();++i){
            if(tmp.size()>0 && s.charAt(i)!=' ')
                tmp.clear();
            while(s.charAt(i)!=' '){
                tmp.add(s.charAt(i));
                ++i;
            }
        }
        return tmp.size()>0?tmp.size():0;
    }
}