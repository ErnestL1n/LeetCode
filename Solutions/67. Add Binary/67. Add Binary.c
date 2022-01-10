
#define max(a,b) (a>b?a:b)

char * addBinary(char * a, char * b){
    
    int carry=0,m=strlen(a),n=strlen(b);
    
    //for carry and '\0'
    int k=max(m,n)+2;
    char *res=(char*)malloc(sizeof(char)*k);
    *res='x';
    *(res+(--k))='\0';
    --k;
    
    for(int i=m-1,j=n-1;i>=0 || j>=0 ||carry;--i,--j){
        int x=i<0?0:*(a+i)-'0';
        int y=j<0?0:*(b+j)-'0';
        carry+=x+y;
        *(res+k)=(carry%2)+'0';
        carry/=2;
        --k;
    }
    // if(*res=='x'){
    //     memmove(res,res+1,sizeof(char)*strlen(res));
    // }
    // or
    if(*res=='x'){
        return res+1;
    }
    return res;
}

