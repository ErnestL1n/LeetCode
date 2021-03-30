class Solution {
public:
    int reinitializePermutation(int n) {
        int res=0;
        vector<int> init(n),a(n);
        iota(begin(init),end(init),0),iota(begin(a),end(a),0);
        while(res==0 or a!=init){
            for(int i=0;i<n;++i){
                if(i%2==0)
                    a[i]=a[i/2];
                else
                    a[i]=a[n/2+(i-1)/2];
            }
            ++res;
        }
        return res;
    }
};

class Solution {
public:
    int reinitializePermutation(int n) {
        int res = 0, i = 1;
        while (res == 0 || i > 1) {
            if (i < n / 2)
                i *= 2;
            else
                i = (i - n / 2) * 2 + 1;
            res++;
        }
        return res;
    }
};