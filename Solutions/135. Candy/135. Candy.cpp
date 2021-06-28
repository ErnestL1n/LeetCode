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

//trick solution,one pass
class Solution {
public:
    int candy(vector<int>& r) {
        int res=1,up=0,down=0,peek=0;
        for(int i=1;i<r.size();++i){
            if(r[i]>r[i-1]){
                peek=++up;
                down=0;
                res+=1+up;
            }else if(r[i]==r[i-1]){
                down=peek=up=0;
                res+=1;
            }
            else if(r[i]<r[i-1]){
                ++down;
                up=0;
                res+=1+down+(peek>=down?-1:0);
            }
        }
        //output candies order:[1,2,3,1,2,4]
        //right output order:[1,2,4,3,2,1]
        return res;
    }
};