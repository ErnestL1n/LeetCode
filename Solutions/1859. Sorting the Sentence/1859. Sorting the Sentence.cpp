// map solution
class Solution {
public:
    string sortSentence(string s) {
        map<int,string> m;
        for(int i=0;i<s.size();++i){
            string tmp="";
            while(!isdigit(s[i])){
                tmp+=s[i++];
            }
            m[s[i]]=tmp;
            ++i;
        }
        string res="";
        for(auto [k,v]:m){
            res+=v;
            res+=' ';
        }
        return res.substr(0,res.size()-1); 
    }
};