class Solution {
public:
    string multiply(string num1, string num2) {
        int m=num1.size(),n=num2.size();
        vector<int> pos(m+n);
        for(int i=m-1;i>=0;--i){
            for(int j=n-1;j>=0;--j){
                int mul=(num1[i]-'0')*(num2[j]-'0');
                int p1=i+j,p2=i+j+1;
                int sum=mul+pos[p2];
                pos[p1]+=sum/10;
                pos[p2]=sum%10;
            }
        }
        string res;
        for(const auto& p:pos){
            if(res.size()!=0 or p!=0){
                res.push_back(p+'0');
            }
        }
        return res.size()?res:"0";
    }
};