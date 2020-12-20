class Solution {
public:
    string reformatNumber(string number) {
        vector<char> tmp;
        for(auto c:number)
            if(c!='-'&&c!=' ')
                tmp.push_back(c);
        string res;
        for(int i=0;i<tmp.size();){
            if(tmp.size()-i==4){
                res+=tmp[i];
                res+=tmp[i+1];
                i+=2;
            }
            else if(tmp.size()-i==2){
                res+=tmp[i];
                res+=tmp[i+1];
                break;
            }
            else if(tmp.size()-i==3){
                res+=tmp[i];
                res+=tmp[i+1];
                res+=tmp[i+2];
                break;
            }
            else{
                res+=tmp[i];
                res+=tmp[i+1];
                res+=tmp[i+2];
                i+=3;
            }
            res+='-';
        }
        return res;
    }
};