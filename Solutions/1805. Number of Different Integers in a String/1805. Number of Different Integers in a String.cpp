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


//two pointers
class Solution {
public:
    int numDifferentIntegers(string w) {
        unordered_set<string> s{""};    //now, s.size()==1
        int i=0;
        for (int j = 0;j<w.size();++j) {
            if(isdigit(w[j])){
                if (i<j and w[i]=='0')
                    ++i;
            }
            else {
                if (i<j)
                    s.insert(w.substr(i,j-i));
                i=j+1;
            }
        }
        s.insert(w.substr(i));
        return s.size()-1;
    }
};