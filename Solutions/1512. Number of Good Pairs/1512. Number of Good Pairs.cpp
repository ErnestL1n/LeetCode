class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int res=0;
        int cnt[101]={};
        for(auto n:nums)
            ++cnt[n];
        for(int i=1;i<=100;++i)
            res+=cnt[i]*(cnt[i]-1)/2;
        return res;
    }
};


//using map
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> m;
        int res=0;
        for(auto n:nums)
            res+=m[n]++;
        return res;
    }
};

//one line
class Solution {
public:
    int numIdenticalPairs(vector<int>& A) {
        return accumulate(A.begin(), A.end(), 0, [count = unordered_map<int, int> {}] (auto a, auto b) mutable { return a + count[b]++;  });
    }
};
