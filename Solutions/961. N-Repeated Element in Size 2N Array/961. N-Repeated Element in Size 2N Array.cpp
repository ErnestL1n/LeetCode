class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int cnt[10000]={};
        for(int a:A)
            if(cnt[a]++==1)
                return a;
        return -1;
    }
};