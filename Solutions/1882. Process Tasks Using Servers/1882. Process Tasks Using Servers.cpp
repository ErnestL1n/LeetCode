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
        priority_queue<ar,vector<ar>,greater<ar>> avail,busy;
        for(int i=0;i<servers.size();++i)
            avail.push({servers[i],i,0});
        for(int i=0;i<tasks.size();++i){
            int t=tasks[i];
            //try to free servers
            while(busy.size()>0 and busy.top()[0]<=i){
                auto [time,weight,index]=busy.top();busy.pop();
                avail.push({weight,index,time});
            }
            if(avail.size()==0){
                auto [time,weight,index]=busy.top();busy.pop();
                res.push_back(index);
                time+=t;
                busy.push({time,weight,index});
            }else{
                auto [weight,index,time]=avail.top();avail.pop();
                res.push_back(index);
                time=i+t;
                busy.push({time,weight,index});
            }
        }
        return res;
    }
};