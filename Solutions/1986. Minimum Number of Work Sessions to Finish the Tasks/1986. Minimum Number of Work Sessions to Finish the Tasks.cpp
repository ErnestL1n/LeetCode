class Solution {
public:
    vector<int> sessions;
    unordered_map<string,int> um;
    string encode(vector<int>& sessions,int pos){
        vector<int> copy=sessions;
        sort(copy.begin(),copy.end());
        string key=to_string(pos)+"$";
        cout << key ;
        for(int i=0;i<copy.size();++i){
            key+=to_string(copy[i])+"$";
        }
        return key;
    }
    int solve(vector<int>& tasks,int n,int sessionTime,int pos){
        if(pos>=n){
            return 0;
        }
        string key=encode(sessions,pos);
        if(um.find(key)!=um.end()){
            return um[key];
        }
        sessions.push_back(tasks[pos]);
        int res=1+solve(tasks,n,sessionTime,pos+1);
        sessions.pop_back();
        for(int i=0;i<sessions.size();++i){
            if(sessions[i]+tasks[pos]<=sessionTime){
                sessions[i]+=tasks[pos];
                res=min(res,solve(tasks,n,sessionTime,pos+1));
                sessions[i]-=tasks[pos];
            }
        }
        return um[key]=res;
    }
    int minSessions(vector<int>& tasks, int sessionTime) {
        return solve(tasks,tasks.size(),sessionTime,0);
    }
};