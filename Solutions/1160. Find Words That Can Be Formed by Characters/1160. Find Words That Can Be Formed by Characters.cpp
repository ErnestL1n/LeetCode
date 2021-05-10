class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int res=0;
        unordered_multiset<char> s(chars.begin(),chars.end());
        for(const auto& w:words){
            auto t=s;
            int k=w.size();
            for(const auto& c:w){
                auto p=t.find(c);
                if(p!=t.end())
                    t.erase(p),--k;
                else
                    break;
            }
            res+=k?0:w.size();
        }
        return res;
    }
};