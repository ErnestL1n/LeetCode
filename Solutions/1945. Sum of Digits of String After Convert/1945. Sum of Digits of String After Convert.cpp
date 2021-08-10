class Solution {
public:
    int getLucky(string s, int k) {
        int res=0;
        string tmp="";
        while(k--){
            //first time for k string->int
            if(res==0){
                for(const auto& c:s)
                    tmp+=to_string(c-'a'+1);
                for(const auto& c:tmp)
                    res+=c-'0';
            }else{
                int tmp=res;
                //reset
                res=0;
                while(tmp>0){
                    res+=tmp%10;
                    tmp/=10;   
                }
            }
        }
        return res;
    }
};