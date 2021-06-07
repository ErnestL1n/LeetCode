//fast,but unclear version
typedef array<int,3> ar;
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        //min heap
        priority_queue<ar,vector<ar>,greater<ar>> avail,busy;
        vector<int> res;
        // time,weight,index
        for(int i=0;i<servers.size();++i)
            avail.push({0,servers[i],i});
        for(int t=0;t<tasks.size();++t){
            while(!busy.empty() and (busy.top()[0]<=t or avail.empty())){
                auto [time,w,i]=busy.top();busy.pop();
                avail.push({time<=t?0:time,w,i});
            }
            auto [time,w,s]=avail.top();avail.pop();
            busy.push({max(time,t)+tasks[t],w,s});
            res.push_back(s);
        }
        return res;
    }
};

//clear version
typedef array<int,3> ar;
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        vector<int> res;
        priority_queue<ar,vector<ar>,greater<ar>> freeServers,usedServers;
        for(int i=0;i<servers.size();++i)
            freeServers.push({servers[i],i,0});
        for(int i=0;i<tasks.size();++i){
            int t=tasks[i];
            //free servers
            while(usedServers.size()>0 and usedServers.top()[0]<=i){
                auto [time,w,index]=usedServers.top();usedServers.pop();
                freeServers.push({w,index,time});
            }
            if(freeServers.empty()){
                auto [time,w,index]=usedServers.top();usedServers.pop();
                res.push_back(index);
                time+=t;
                usedServers.push({time,w,index});
            }else{
                auto [w,index,time]=freeServers.top();freeServers.pop();
                res.push_back(index);
                time=i+t;
                usedServers.push({time,w,index});
            }
        }
        return res;
    }
};