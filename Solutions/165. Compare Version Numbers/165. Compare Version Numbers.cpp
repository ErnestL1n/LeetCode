class Solution {
public:
    vector<string> split(string& s,string& delimiter){
        vector<string> res;
        size_t last=0,next=0;
        // find(string,start_pos)
        while((next=s.find(delimiter,last))!=string::npos){
            res.push_back(s.substr(last,next-last));
            last=next+delimiter.size();
        }
        res.push_back(s.substr(last));
        return res;
    }
              
    int compareVersion(string version1, string version2) {
        string delimiter=".";
        vector<string> v1=split(version1,delimiter);
        vector<string> v2=split(version2,delimiter);
        for(int i=0;i<max(v1.size(),v2.size());++i){
            int a=i<v1.size()?stoi(v1[i]):0;
            int b=i<v2.size()?stoi(v2[i]):0;   
            if(a<b){
                return -1;
            }
            if(a>b){
                return 1;
            }
        }
        return 0;
    }
};