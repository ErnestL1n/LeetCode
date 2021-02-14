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


//Trick 
class Solution {
public:
    int minOperations(string s) {
        int res=0,n=s.size();
        for(int i=0;i<n;++i)
            if(s[i]-'0'!=i%2)
                ++res;
        return min(res,n-res);
    }
};