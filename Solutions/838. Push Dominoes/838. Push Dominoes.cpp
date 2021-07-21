class Solution {
public:
    string pushDominoes(string dom) {
        dom='L'+dom+'R';
        string res="";
        for(int i=0,j=1;j<dom.size();++j){
            if(dom[j]=='.')
                continue;
            int mid=j-i-1;
            if(i>0)
                res+=dom[i];
            if(dom[i]==dom[j])
                res+=string(mid,dom[i]);
            else if(dom[i]=='L' and dom[j]=='R')
                res+=string(mid,'.');
            else
                res+=string(mid/2,'R')+string(mid%2,'.')+string(mid/2,'L');
            i=j;
        }
        return res;
    }
};