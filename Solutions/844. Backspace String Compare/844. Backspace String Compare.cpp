class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i=s.size()-1,j=t.size()-1,back;
        while(true){
            back=0;
            while(i>=0 and (back>0 or s[i]=='#')){
                back+=s[i--]=='#'?1:-1;
            }
            back=0;
            while(j>=0 and (back>0 or t[j]=='#')){
                back+=t[j--]=='#'?1:-1;
            }
            if(i>=0 and j>=0 and s[i]==t[j]){
                --i;
                --j;
            }else{
                break;
            }
        }
        return i==-1 and j==-1;
    }
};