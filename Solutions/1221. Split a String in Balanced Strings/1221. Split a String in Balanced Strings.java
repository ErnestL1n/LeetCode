class Solution {
    public int balancedStringSplit(String s) {
        int res=0,lcnt=0,rcnt=0;
        for(var c:s.toCharArray()){
            if(c=='R')
                ++rcnt;
            else if(c=='L')
                ++lcnt;
            if(rcnt!=0 && rcnt==lcnt)
                ++res;
        }
        return res;
    }
}

class Solution {
    public int balancedStringSplit(String s) {
        int res=0,cnt=0;
        for(var c:s.toCharArray()){
            cnt+=c=='L'?1:-1;
            if(cnt==0)++res;
        }
        return res;
    }
}