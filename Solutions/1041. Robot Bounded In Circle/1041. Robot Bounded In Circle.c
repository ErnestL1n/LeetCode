

bool isRobotBounded(char * ins){
    int x=0,y=0,i=0;
    int d[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    while(*ins!='\0'){
        if(*ins=='R'){
            i=(i+1)%4;
        }else if(*ins=='L'){
            i=(i+3)%4;
        }else{
            x+=d[i][0],y+=d[i][1];
        }
        ++ins;
    }
    return (x==0 && y==0) || i>0;
}