class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int cnt1=0,flip=0;
        for(const auto& c:s){
            if(c=='1')
                ++cnt1;
            else
                ++flip;
            flip=min(cnt1,flip);
        }
        return flip;
    }
};