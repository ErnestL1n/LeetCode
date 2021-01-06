class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int res=0;
        unordered_set<char> s;
        for(int i=0;i<allowed.size();++i){
            s.insert(allowed[i]);
        }
        for(auto w:words){
            for(int i=0;i<w.size();++i){
                if(s.find(w[i])==s.end())
                    break;
                if(i==w.size()-1)
                    ++res;
            }
        }
        return res;
    }
};