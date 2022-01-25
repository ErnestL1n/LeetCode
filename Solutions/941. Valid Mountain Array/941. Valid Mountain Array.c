#define and &&

bool validMountainArray(int* arr, int arrSize){
    int i=0,j=arrSize-1;
    while(i<arrSize-1 and arr[i+1]-arr[i]>0)
        ++i;
    while(j>0 and arr[j-1]-arr[j]>0)
        --j;
    return i==j and i>0 and j<arrSize-1;
}