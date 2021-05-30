class Solution {
public:
    bool isSumEqual(string f, string s, string t) {
        int fn=0,sn=0,tn=0;
        for(const auto& c:f)
            fn=fn*10+(c-'a');       
        //cout << fn <<"\n";
        for(const auto& c:s)
            sn=sn*10+(c-'a');
        //cout << sn <<"\n";
        for(const auto& c:t)
            tn=tn*10+(c-'a');
        //cout << tn <<"\n";
        return sn+fn==tn;
    }
};