class Solution {
public:
    int totalMoney(int n) {
        int res=0,m=1;
        for(int i=0;i<n;++i){
            if(i%7==0&&i!=0)
                m-=6;
            res+=m;
            ++m;
        }
        return res;
    }
};

//more concise
class Solution {
public:
    int totalMoney(int n) {
        int res=0;
        for(int i=0;i<n;++i)
            res+=i%7+i/7+1;
        return res;
    }
};