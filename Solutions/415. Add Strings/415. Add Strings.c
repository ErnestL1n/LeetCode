#define max(a,b) (a>b?a:b)

char * addStrings(char * num1, char * num2){
    int m=strlen(num1),n=strlen(num2);
    
    //for carry and '\0'
    int k=max(m,n)+2,carry=0;
    char* res=(char*)malloc(sizeof(char)*k);
    *res='x';
    *(res+(--k))='\0';
    --k;
    
    for(int i=m-1,j=n-1;i>=0 || j>=0 ||carry;--i,--j){
        int x=i<0?0:*(num1+i)-'0';
        int y=j<0?0:*(num2+j)-'0';
        carry+=x+y;
        *(res+k)=(carry%10)+'0';
        carry/=10;
        --k;
    }
    if(*res=='x'){
        return res+1;
    }
    return res;
}