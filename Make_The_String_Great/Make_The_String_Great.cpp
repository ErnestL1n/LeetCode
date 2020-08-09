class Solution {
public:
    string makeGood(string s) {
		string res;
        vector<char> v;
		for(int i=0;i<s.length();++i){
			if(v.size()&&abs(s[i]-v.back()==32))
				v.pop_back();
			else
				v.push_back(s[i]);
		}
		for(auto c:v)res+=c;
		return res;
    }
};