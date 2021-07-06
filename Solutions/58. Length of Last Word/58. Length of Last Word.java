class Solution {
    public int lengthOfLastWord(String s) {
        s+=' ';
        String tmp="";
        for(int i=0;i<s.length();++i){
            if(tmp.length()>0 && s.charAt(i)!=' ')
                tmp="";
            while(s.charAt(i)!=' '){
                tmp+=s.charAt(i);
                ++i;
            }
        }
        return tmp.length()>0?tmp.length():0;
    }
}