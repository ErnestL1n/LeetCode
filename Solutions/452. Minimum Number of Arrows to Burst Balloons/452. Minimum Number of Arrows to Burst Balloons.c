int cmp(int**,int**);

int findMinArrowShots(int** points, int pointsSize, int* pointsColSize){
    int st=0,res=1;
    qsort(points,pointsSize,sizeof(int*),cmp);
    for(int i=1;i<pointsSize;++i){
        if(points[st][1]>=points[i][0]){
            continue;
        }
        ++res;
        st=i;
    }
    return res;
}

int cmp(int** a,int** b){
    int x=(*a)[1],y=(*b)[1];
    if(x>y){
        return 1;
    }else if(x<y){
        return -1;
    }else{
        return 0;
    }
}