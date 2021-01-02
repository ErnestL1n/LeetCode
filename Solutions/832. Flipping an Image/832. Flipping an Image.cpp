class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& a) {
        for(auto& row:a){
            reverse(row);
            invert(row);
        }
        return a;
    }
    void reverse(vector<int>& row){
        int l=0,r=row.size()-1;
        while(l<r){
            int tmp=row[l];
            row[l]=row[r];
            row[r]=tmp;
            ++l;--r;
        }
    }
    void invert(vector<int>& row){
        for(int i=0;i<row.size();++i){
            if(row[i])
                row[i]=0;
            else
                row[i]=1;
        }
    }
};