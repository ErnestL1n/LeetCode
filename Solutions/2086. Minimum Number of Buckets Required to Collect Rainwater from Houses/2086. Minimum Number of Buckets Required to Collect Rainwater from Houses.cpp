class Solution {
public:
    int minimumBuckets(string st) {
        for(int i=0;i<st.size();++i){
            if(st[i]=='H'){
                if(i>0 and st[i-1]=='B'){
                    continue;
                }
                if(i<st.size()-1 and st[i+1]=='.'){
                    st[i+1]='B';
                }else if(i>0 and st[i-1]=='.'){
                    st[i-1]='B';
                }else{
                    return -1;
                }
            }    
        }
        return count(st.begin(),st.end(),'B');
    }
};