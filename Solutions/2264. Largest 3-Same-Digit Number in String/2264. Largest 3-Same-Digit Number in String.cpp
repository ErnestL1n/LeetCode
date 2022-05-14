class Solution {
public:
    string largestGoodInteger(string num) {
        int res=-1;
        for(int i=2;i<num.size();++i){
            if(num[i]==num[i-1] and num[i]==num[i-2]){
                res=max(res,num[i]-'0');
            }
        }
        return res==-1?"":string(3,res+'0');
    }
};