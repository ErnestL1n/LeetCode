class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i=0;
        for(;i<word.size();++i)
            if(ch==word[i])
                break;
        if(i==word.size())
            return word;
        string res;
        for(int j=i;j>=0;--j)
            res+=word[j];
        return res+word.substr(i+1);
    }
};

//shorter
class Solution {
public:
    string reversePrefix(string word, char ch) {
        auto p=word.find(ch);
        if(p!=string::npos)
            reverse(begin(word),begin(word)+p+1);
        return word;
    }
};

//more shorter
class Solution {
public:
    string reversePrefix(string word, char ch) {
        reverse(begin(word),begin(word)+word.find(ch)+1);
        return word;
    }
};