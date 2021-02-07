//StraightForward counting
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int cnt[101]={},res=0;
        for(int n:nums)
            ++cnt[n];
        for(int i=1;i<=100;++i)
            if(cnt[i]==1)
                res+=i;
        return res;
    }
};

//STL accumulate
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int n:nums)
            ++m[n];
        return accumulate(begin(m),end(m),0,[](int sum,const pair<int,int>& p){
            return sum+(p.second==1?p.first:0);
        });
    }
};