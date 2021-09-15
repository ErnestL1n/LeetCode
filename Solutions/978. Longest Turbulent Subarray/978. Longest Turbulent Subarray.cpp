class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        vector<int> sign;
        int n=arr.size();
        for(int i=1;i<n;++i){
            if(arr[i]-arr[i-1]>0)
                sign.push_back(1);
            else if(arr[i]-arr[i-1]<0)
                sign.push_back(0);
            // == case
            else
                sign.push_back(-1);
        }
        int res=1,len=1;
        int s=1;
        for(int i=0;i<sign.size();++i){
            if(sign[i]==(s^1)){
                res=max(++len,res);
            }else{
                len=1;
            }
            s^=1;
        }
        s=0;
        len=1;
        for(int i=0;i<sign.size();++i){
            if(sign[i]==(s^1)){
                res=max(++len,res);
            }else{
                len=1;
            }
            s^=1;
        }
        return res;
    }
};