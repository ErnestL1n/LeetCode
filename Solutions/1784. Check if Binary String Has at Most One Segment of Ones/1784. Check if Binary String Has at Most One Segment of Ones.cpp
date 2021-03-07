class Solution {
public:
    bool checkOnesSegment(string s) {
        bool valid=false;
        for(int i=0;i<s.size();++i){
            if(s[i]=='1'){
                if(valid)
                    return false;
            }else
                valid=true;
        }
        return true;
    }
};


class Solution {
public:
    bool checkOnesSegment(string s) {
        for(int i=1;i<s.size();++i)
            if(s[i-1]=='0'&&s[i]=='1')
                return false;
        return true;
    }
};