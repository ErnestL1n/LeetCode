class Solution {
public:
    string removeDuplicates(string s) {
        string res="";
        for(const auto& c:s){
            if(c==res.back())
                res.pop_back();
            else
                res.push_back(c);
        }
        return res;
    }
};