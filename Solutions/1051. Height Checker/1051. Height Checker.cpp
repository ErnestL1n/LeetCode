class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int res=0,currh=0;
        vector<int> cnt(101,0);
        for(int h:heights){
            ++cnt[h];
        }
        for(int h:heights){
            while(!cnt[currh])
                ++currh;
            if(currh!=h)
                ++res;
            --cnt[currh];
        }
        return res;
    }
};