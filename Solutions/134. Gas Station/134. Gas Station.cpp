class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int st=0,total=0,tank=0;
        for(int i=0;i<gas.size();++i){
            if((tank=tank+gas[i]-cost[i])<0){
                st=i+1;
                total+=tank;
                tank=0;
            }
        }
        return (total+tank<0)?-1:st;
    }
};