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
		//good points - a one-liner implementation does create a temporary string for w1[i] + w2[i].
        while(p<sz)
            res+=string()+word1[p]+word2[p++];
		/* same as above one line implementation,but doesn't create a temporary string for w1[i] + w2[i]
		while(p<sz){
            res+=word1[p];
            res+=word2[p++];
        }
		*/
        return res+word1.substr(p)+word2.substr(p);
    }
};


//opt version
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0,j=0,sz1=word1.size(),sz2=word2.size();
        string res;
        while(i<sz1||j<sz2){
            if(i<sz1)
                res+=word1[i++];
            if(j<sz2)
                res+=word2[j++];
        }
        return res;
    }
};