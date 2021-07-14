//bucket sort
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> m;
        for(const auto& c:s)
            ++m[c];
        //create bucket number from "0" to "s.size()+1"
        vector<vector<char>> bucket(s.size()+1);
        for(const auto& [k,v]:m)
            bucket[v].push_back(k);
        string res="";
        //push_back from the largest size one
        for(int i=bucket.size()-1;i>=0;--i){
            for(char c:bucket[i])
                for(int j=0;j<i;++j)
                    res+=c;
        }
        return res;
    }
};