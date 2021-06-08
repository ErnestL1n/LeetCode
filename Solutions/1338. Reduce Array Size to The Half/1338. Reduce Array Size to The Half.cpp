//easy version
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

//hashmap+multiset
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int res=0,n=arr.size(),cnt=0;
        unordered_map<int,int> m;
        multiset<int,greater<int>> s;
        for(const auto& a:arr)
            ++m[a];
        for(const auto& p:m)
            s.insert(p.second);
        for(auto it=s.begin();cnt<n/2;++it){
            ++res;
            cnt+=*it;
        }
        return res;
    }
};