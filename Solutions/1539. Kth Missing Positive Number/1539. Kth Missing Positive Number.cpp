class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int> s(arr.begin(),arr.end());
        int cnt=0,res=0;
        for(int i=1;i<=2000;++i){
            if(s.find(i)==s.end())
                ++cnt;
            if(cnt==k){
                res=i;
                break;
            }
        }
        return res;
    }
};