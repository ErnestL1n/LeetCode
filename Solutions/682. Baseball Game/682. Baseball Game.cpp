class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> stk;
        for(int i=0;i<ops.size();++i){
            if(ops[i]=="C"){
                stk.pop_back();
            }else if(ops[i]=="D"){
                stk.push_back(stk.back()*2);
            }else if(ops[i]=="+"){
                int x=stk.back();stk.pop_back();
                int y=stk.back();
                stk.push_back(x);
                stk.push_back(x+y);
            }else{
                stk.push_back(stoi(ops[i]));
            }
        }
        return accumulate(stk.begin(),stk.end(),0);
    }
};