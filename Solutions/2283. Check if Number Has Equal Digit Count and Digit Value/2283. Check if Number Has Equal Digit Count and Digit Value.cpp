class Solution {
public:
    bool digitCount(string num) {
        int cnt[10]={};
        for(auto& n:num){
            ++cnt[n-'0'];
        }
        for(int i=0;i<num.size();++i){
            if(cnt[i]!=num[i]-'0'){
                return false;
            }
        }
        return true;
    }
};