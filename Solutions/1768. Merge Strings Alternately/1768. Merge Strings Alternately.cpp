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