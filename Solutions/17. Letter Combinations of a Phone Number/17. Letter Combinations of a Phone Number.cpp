class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.size()==0){
            return res;
        }
        vector<string> numbers={"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        res.push_back("");
        for(int i=0;i<digits.size();++i){
            int x=digits[i]-'0';
            while(res[0].size()==i){
                string t=res[0];
                res.erase(res.begin());
                for(char s:numbers[x]){
                    res.push_back(t+s);
                }
            }
        }
        return res;
    }
};