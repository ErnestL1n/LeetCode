class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        vector<vector<string>> res;
        string cur="";
        auto it=products.begin();
        for(char c:searchWord){
            cur+=c;
            vector<string> suggested;
            it=lower_bound(it,products.end(),cur);
            for(int i=0;i<3 and it+i!=products.end();++i){
                string& s=*(it+i);
                if(s.find(cur)){
                    break;
                }
                suggested.push_back(s);
            }
            res.push_back(suggested);
        }
        return res;
    }
};class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> s(words.begin(),words.end());
        for(string w:s){
            for(int i=1;i<w.size();++i){
                s.erase(w.substr(i));
            }
        }
        int res=0;
        for(string w:s){
            res+=w.size()+1;
        }
        return res;
    }
};