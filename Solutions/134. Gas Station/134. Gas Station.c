

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize){
    int st=0,total=0,tank=0;
    for(int i=0;i<gasSize;++i){
        if((tank=tank+gas[i]-cost[i])<0){
            st=i+1;
            total+=tank;
            tank=0;
        }
    }
    return (total+tank<0)?-1:st;
}