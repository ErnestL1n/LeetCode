class Solution {
public:
    bool checkString(string s) {
        char a=false,b=false;
        for(int i=0;i<s.size();++i){
            if(s[i]=='a'){
                a=true;
                if(a and b){
                    return false;
                }
            }else{
                b=true;
            }
        }
        return true;
    }
};

// neighbor "ba"
// string::npos
class Solution {
public:
    bool checkString(string s) {
        return s.find("ba")==string::npos;
    }
};

//is sorted
class Solution {
public:
    bool checkString(string s) {
        return is_sorted(s.begin(),s.end());
    }
};

