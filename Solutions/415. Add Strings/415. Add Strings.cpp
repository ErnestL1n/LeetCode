//signed integer overflow
class Solution {
public:
    string addStrings(string num1, string num2) {
        long n1=0,n2=0;
        for(int i=0;i<num1.size();++i)
            n1=n1*10+(num1[i]-'0');
        for(int i=0;i<num2.size();++i)
            n2=n2*10+(num2[i]-'0');
        return to_string(n1+n2);
    }
};

//AC version
class Solution {
public:
    string addStrings(string num1, string num2) {
        string res="";
        int carry=0;
        for(int i=num1.size()-1,j=num2.size()-1;i>=0 or j>=0 or carry==1;--i,--j){
            int x=i<0?0:num1[i]-'0';
            int y=j<0?0:num2[j]-'0';
            res+=to_string((x+y+carry)%10);
            carry=(x+y+carry)/10;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};