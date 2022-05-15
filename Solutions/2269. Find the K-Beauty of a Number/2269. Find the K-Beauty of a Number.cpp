class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s=to_string(num);
        int res=0;
        for(int i=0;i<=s.size()-k;++i){
            string sub=s.substr(i,k);
            int n=stoi(sub);
            if(n>0 and num%n==0){
                ++res;
            }
        }
        return res;
    }
};