class Solution {
public:
    string simplifyPath(string path) {
        string res,tmp;
        vector<string> x;
        stringstream ss(path);
        while(getline(ss,tmp,'/')){
            if(tmp=="" or tmp=="."){
                continue;
            }
            if(tmp==".." and x.size()){
                x.pop_back();
            }else if(tmp!=".."){
                x.push_back(tmp);
            }
        }
        for(auto& s:x){
            res+="/"+s;
        }
        return res.size()?res:"/";
    }
};