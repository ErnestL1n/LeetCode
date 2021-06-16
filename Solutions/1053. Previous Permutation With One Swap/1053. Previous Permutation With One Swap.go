func prevPermOpt1(arr []int) []int {
    n,idx:=len(arr),-1
    if n<=1{
        return arr
    }
    for i:=n-1;i>0;i-=1{
        if arr[i]<arr[i-1]{
            idx=i-1
            break
        }
    }
    if idx==-1{
        return arr
    }
    for i:=n-1;i>idx;i-=1{
        if arr[idx]>arr[i] && arr[i]!=arr[i-1]{
            arr[idx],arr[i]=arr[i],arr[idx]
            break
        }
    }
    return arr
}