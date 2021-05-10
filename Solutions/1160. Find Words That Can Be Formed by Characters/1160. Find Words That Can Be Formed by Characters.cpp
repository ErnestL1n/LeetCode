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



class Solution {
public:
    int countCharacters(vector<string>& words, string chars,int res=0) {
        vector<int> cnt(26);
        for(const auto& c:chars)
            ++cnt[c-'a'];
        for(const auto& w:words){
            vector<int> tmp=cnt;
            bool match=true;
            for(auto c:w){
                if(--tmp[c-'a']<0){
                    match=false;
                    break;
                }
            }
            if(match)
                res+=w.size();
        }
        return res;
    }
};