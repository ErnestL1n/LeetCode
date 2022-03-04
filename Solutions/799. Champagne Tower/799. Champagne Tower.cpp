class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> res(101,vector<double>(101));
        res[0][0]=poured;
        for(int i=0;i<100;++i){
            for(int j=0;j<=i;++j){
                if(res[i][j]>=1){
                    res[i+1][j]+=(res[i][j]-1)/2.0;
                    res[i+1][j+1]+=(res[i][j]-1)/2.0;
                    res[i][j]=1;
                }
            }
        }
        return res[query_row][query_glass];
    }
};

// time space opt
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> res(102);
        res[0]=poured;
        for(int row=1;row<=query_row;++row){
            for(int i=row;i>=0;--i){
                res[i+1]+=res[i]=max(0.0,(res[i]-1)/2);
            }
        }
        return min(res[query_glass],1.0);
    }
};