class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int record[1001]={};
        for(int i=0;i<target.size();++i){
            ++record[target[i]];
            --record[arr[i]];
        }
        for(int i=0;i<1001;++i)
            if(record[i]!=0)
                return false;
        return true;
    }
};

//multiset
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        return unordered_multiset<int>(target.begin(),target.end())==unordered_multiset<int>(arr.begin(),arr.end());
    }
};