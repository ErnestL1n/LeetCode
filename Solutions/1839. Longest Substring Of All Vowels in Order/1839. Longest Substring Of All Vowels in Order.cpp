class Solution {
public:
    int longestBeautifulSubstring(string word) {
        const int n=word.size();
        int cnt=1,len=1,max_len=0;
        for(int i=1;i<n;++i){
            if(word[i-1]==word[i])
                ++len;
            else if(word[i-1]<word[i])
                ++len,++cnt;
            else
                len=1,cnt=1;
            if(cnt==5)
                max_len=max(max_len,len);
        }
        return max_len; 
    }
};