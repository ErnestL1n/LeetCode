class Solution {
public:
    string mergeAlternately(string w1, string w2) {
        int i = 0, j = 0;
        string res;
        while (i < w1.size() && j < w2.size())
            res += string() + w1[i++] + w2[j++];
        return res + w1.substr(i) + w2.substr(j);
    }
};




class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int p=0,sz=min(word1.size(),word2.size());
        string res;
        while(p<sz){
            res+=word1[p];
            res+=word2[p++];
        }
        return res+word1.substr(p)+word2.substr(p);
    }
};