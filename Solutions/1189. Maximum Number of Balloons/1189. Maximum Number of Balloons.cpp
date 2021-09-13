class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int res=INT_MAX;
        int cnt[26]={};
        for(const auto& c:text)
            if(c=='a' or c=='b' or c=='l' or c=='o' or c=='n')
                ++cnt[c-'a'];
        cnt['l'-'a']/=2;
        cnt['o'-'a']/=2;
        compare('b'-'a',cnt,res);
        compare('l'-'a',cnt,res);
        compare('a'-'a',cnt,res);
        compare('o'-'a',cnt,res);
        compare('n'-'a',cnt,res);
        return res;
    }
    void compare(int i,int (&cnt)[26],int& res){
        res=min(res,cnt[i]);
    }
};