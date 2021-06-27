class Solution {
public:
    int candy(vector<int>& r) {
        int n=r.size(),res=0;
        vector<int> tmp(n,1);
        for(int i=1;i<n;++i)
            if(r[i]>r[i-1])
                tmp[i]=tmp[i-1]+1;
        for(int i=n-1;i>0;--i)
            if(r[i-1]>r[i])
                tmp[i-1]=max(tmp[i-1],tmp[i]+1);
        for(const auto& t:tmp)
            res+=t;
        return res;
    }
};