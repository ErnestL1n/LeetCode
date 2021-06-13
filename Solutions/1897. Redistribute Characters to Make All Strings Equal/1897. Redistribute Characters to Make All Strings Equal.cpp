class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int cnt[26]={};
        for(const auto& w:words){
          for(const auto& c:w)
              ++cnt[c-'a'];
        }
        for(auto x:cnt)
            if(x%words.size())
                return false;
        return true;
    }
};