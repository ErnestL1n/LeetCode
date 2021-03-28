class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> s;
        string tmp="";
        word+='w';  //used to handle the ending number of the string --->flag
        for(auto& ch:word){
            if(isdigit(ch))
                tmp+=ch;
            else{   //--->consider the flag
                if(tmp.size()){
                    while(tmp.size()>1 and tmp[0]=='0')   //"0b0" will pass
                        tmp=tmp.substr(1);
                    s.insert(tmp);
                    tmp="";
                }
            }
        }
        // for(auto k:s){
        //     cout<<k<<"\n";
        // }
        return s.size();
    }
};