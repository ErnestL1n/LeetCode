

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize){
    int st=0,gassum=0,costsum=0,g=0;
    for(int i=0;i<gasSize;++i){
        gassum+=gas[i],costsum+=cost[i];
        g+=gas[i]-cost[i];
        if(g<0){
            st=i+1;
            g=0;
        }
    }
    return gassum>=costsum?st:-1;
}