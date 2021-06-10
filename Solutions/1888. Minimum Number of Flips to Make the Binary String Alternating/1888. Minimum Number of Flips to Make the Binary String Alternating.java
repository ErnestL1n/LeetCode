// space and time optimization
class Solution {
    public int minFlips(String s) {
        int n=s.length(),cnt1=0,cnt2=0,res=n;
        for(int i=0;i<2*n;++i){
            var c=s.charAt(i%n);
            var cc=i%2==0?'1':'0';
            if(c!=cc)
                ++cnt1;
            else
                ++cnt2;
            if(i>=n){
                int idx=i-n;
                cc=idx%2==0?'1':'0';
                if(s.charAt(idx)!=cc)
                    --cnt1;
                else
                    --cnt2;
            }
            if(i>=n-1){
                res=Math.min(Math.min(res,cnt1),cnt2);
            }
        }
        return res;
    }
}