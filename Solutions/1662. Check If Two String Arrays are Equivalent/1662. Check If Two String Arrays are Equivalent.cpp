class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string tmp="";
        int i=0;
        for(const auto& w:word1)
            for(const auto& c:w)
                tmp+=c;
        for(const auto& w:word2)
            for(const auto& c:w)
                if(c!=tmp[i++])
                    return false;
        return true;
    }
};

//quick version
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int arridx1=0,arridx2=0,idx1=0,idx2=0;
        while(arridx1<word1.size() and arridx2<word2.size()){
            if(word1[arridx1][idx1]!=word2[arridx2][idx2])
                return false;
            if(idx1==word1[arridx1].size()-1)
                idx1=0,++arridx1;
            else
                ++idx1;
            if(idx2==word2[arridx2].size()-1)
                idx2=0,++arridx2;
            else
                ++idx2;
        }
        return arridx1==word1.size() and arridx2==word2.size();
    }
};

//shorter
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int arridx1=0,arridx2=0,idx1=0,idx2=0;
        while(arridx1<word1.size() and arridx2<word2.size()){
            if(word1[arridx1][idx1]!=word2[arridx2][idx2])
                return false;
            idx1=(++idx1)%word1[arridx1].size();
            idx2=(++idx2)%word2[arridx2].size();
            if(idx1==0)++arridx1;
            if(idx2==0)++arridx2;
        }
        return arridx1==word1.size() and arridx2==word2.size();
    }
};