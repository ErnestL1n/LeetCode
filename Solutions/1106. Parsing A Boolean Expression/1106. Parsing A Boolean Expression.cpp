class Solution {
public:
    bool parseBoolExpr(string expression) {
        int st=0;
        return parse(expression,st);
    }
    bool parse(string& exp,int& st){
        char c=exp[st++];
        if(c=='t'){
            return true;
        }
        if(c=='f'){
            return false;
        }
        if(c=='!'){
            bool res=!parse(exp,++st);
            ++st;
            return res;
        }
        bool is_and=c=='&';
        //trick part
        bool res=is_and;
        ++st;
        while(1){
            if(is_and){
                res&=parse(exp,st);
            }else{
                res|=parse(exp,st);
            }
            // if it is a comma ,continue
            if(exp[st++]==')'){
                break;
            }
        }
        return res;
    }
};