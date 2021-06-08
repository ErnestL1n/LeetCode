class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        int cnt[100001]={};
        for(const auto& a:arr)
            ++cnt[a];
        sort(begin(cnt),end(cnt),greater());
        int res=0,acc=0,i=0;
        while(acc<n/2){
            acc+=cnt[i++];
            ++res;
        }
        return res;
    }
};