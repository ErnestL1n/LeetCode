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

// clean version
// For each A[i]
// inc: The length of current valid sequence which ends with two increasing numbers
// dec: The length of current valid sequence which ends with two decreasing numbers
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int dec=1,inc=1,res=1;
        for(int i=1;i<arr.size();++i){
            if(arr[i]>arr[i-1]){
                inc=dec+1;
                dec=1;
            }else if(arr[i]<arr[i-1]){
                dec=inc+1;
                inc=1;
            }else{
                inc=dec=1;
            }
            res=max(res,max(inc,dec));
        }
        return res;
    }
};