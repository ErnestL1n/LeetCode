class Solution {
    public String modifyString(String s) {
        char[] tmp=s.toCharArray();
        for(int i=0;i<s.length();++i)
            if(tmp[i]=='?')
                for(tmp[i]='a';tmp[i]<='c';++tmp[i])
                    if((i==0||tmp[i-1]!=tmp[i])&&(i==s.length()-1||tmp[i+1]!=tmp[i]))
                        break;
        return new String(tmp);
    }
}