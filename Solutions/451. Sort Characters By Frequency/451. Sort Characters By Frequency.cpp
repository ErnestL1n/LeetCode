//bucket sort
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> m;
        for(const auto& c:s)
            ++m[c];
        //use int(bucket of size i) to access vector<char>(bucket)
        vector<vector<char>> bucket(s.size()+1);
        for(const auto& [k,v]:m)
            bucket[v].push_back(k);
        string res="";
        for(int i=bucket.size()-1;i>=0;--i){
            if(bucket[i].size()){
                for(const auto& c:bucket[i])
                    for(int j=0;j<i;++j)
                        res+=c;
            }
        }
        return res;
    }
};