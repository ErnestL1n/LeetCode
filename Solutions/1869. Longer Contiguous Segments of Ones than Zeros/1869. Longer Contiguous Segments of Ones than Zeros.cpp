class Solution {
public:
    bool checkZeroOnes(string s) {
        int mzs,zs=0,mos,os=0;
        for(const auto& c:s){
            if(c=='1')
                ++os,mos=max(mos,os),zs=0;
            else
                ++zs,mzs=max(mzs,zs),os=0;
        }
        return mos>mzs;
    }
};