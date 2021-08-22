class Solution {
public:
    int minTimeToType(string word) {
        int res=word.size();
        auto pre='a';
        for(const auto& c:word){
            int val=abs((c-pre)%26);
            res+=min(val,26-val);
            pre=c;
        }
        return res;
    }
};