class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int res=0,mask=0;
        for(int i=31;i>=0;--i){
            mask=mask|(1<<i);
            unordered_set<int> s;
            for(int n:nums){
                s.insert(n&mask);
            }
            int tmp=res|(1<<i);
            for(int prefix:s){
                if(s.find(tmp^prefix)!=s.end()){
                    res=tmp;
                    break;
                }
            }
        }
        return res;
    }
};