class Solution {
public:
    int minOperations(string s) {
        int f0=0,f1=1,cnt1=0,cnt2=0;
        for(char c:s){
            cnt1+=c-'0'!=f0;
            cnt2+=c-'0'!=f1;
            swap(f0,f1);
        }
        return min(cnt1,cnt2);
    }
};