class Solution {
    public String reformatNumber(String number) {
        String tmp="";
        for(var c:number.toCharArray())
            if(c!=' '&&c!='-')
                tmp+=c;
        String res="";
        for(int i=0;i<tmp.length();){
            if(tmp.length()-i==4){
                res+=tmp.charAt(i);
                res+=tmp.charAt(i+1);
                i+=2;
            }
            else if(tmp.length()-i==3){
                res+=tmp.charAt(i);
                res+=tmp.charAt(i+1);
                res+=tmp.charAt(i+2);
                break;
            }
            else if(tmp.length()-i==2){
                res+=tmp.charAt(i);
                res+=tmp.charAt(i+1);
                break;
            }
            else{
                res+=tmp.charAt(i);
                res+=tmp.charAt(i+1);
                res+=tmp.charAt(i+2);
                i+=3;
            }
            res+='-';
        }
        return res;
    }
}