class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long length=2,apples=8;
        // // apples=4*(((length/2)+.......+length)*2-length)-2*length
        // long long apples=12;
        // while(apples<neededApples){
        //     ++length;
        //     for(int i)
        // }
        //int o=0;
//         for(int i=2;i<20;i+=2){
//             // for(int j=i/2;j<=i;++j){
//             //     o+=j;
//             // }
//             // cout<< 4*(2*o-i)-2*i <<"\n";
            
//             cout<< 8*count(i)-i*6 <<"\n";
//         }
        // long long lo=2,hi=1e5,outside=8;
        // while(lo<hi){
        //     apples+=outside;
        //     auto mid=(lo+hi)/2;
        //     outside=8*count(mid)-6*mid;
        //     if(apples<neededApples and outside<neededApples)
        //         lo=mid+2;
        //     else
        //         hi=mid;
        // }
        // return 4*lo;
        long long outside=8;
        while(apples<neededApples and outside<neededApples){
            length+=2;
            apples+=outside;
            outside=8*((double)3*pow(length,2)/8+(double)length*3/4)-6*length;
        }
        //cout<< 8*count(1260)-1260*6 <<"\n";
        if(outside>=neededApples)
            return length*4;
        else
            return (length-2)*4;
    }
    // long long count(long long length){
    //     long long res=0;
    //     for(long i=length/2;i<=length;++i)
    //         res+=i;
    //     return res;
    // }
    // 3x/4*(x/2+1)=3x^2/8 +3x/4
};