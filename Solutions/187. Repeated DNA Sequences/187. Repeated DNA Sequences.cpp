class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> set,res;
        for(int i=0;i+9<s.size();++i){
            string ten=s.substr(i,10);
            if(set.find(ten)!=set.end()){
                res.insert(ten);
            }
            set.insert(ten);
        }
        return vector<string>(res.begin(),res.end());
    }
};