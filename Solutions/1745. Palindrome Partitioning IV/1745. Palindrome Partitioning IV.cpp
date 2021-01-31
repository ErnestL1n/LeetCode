//BF
class Solution {
public:
    bool checkPartitioning(string s) {
        for(int i=2;i<s.size();++i){
            if(isPal(s,i,s.size()-1)){
                for(int j=1;j<i;++j)
                    if(isPal(s,0,j-1)&&isPal(s,j,i-1))
                        return true;
            }
        }
        return false;
    }
    bool isPal(string& s,int i,int j){
        while(i<j)
            if(s[i++]!=s[j--])
                return false;
        return true;
    }
};

//DP 
class Solution {
public:
    bool isPal[2000][2000]={};
    bool checkPartitioning(string s) {
        for(int i=s.size()-1;i>=0;--i){
            for(int j=i;j<s.size();++j)
                isPal[i][j]=s[i]==s[j]?(i+1>=j)||isPal[i+1][j-1]:false;
        }
        for(int i=2;i<s.size();++i){
            if(isPal[i][s.size()-1]){
                for(int j=1;j<i;++j)
                    if(isPal[0][j-1]&&isPal[j][i-1])
                        return true;
            }
        }
        return false;
    }
};