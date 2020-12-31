func countGoodTriplets(arr []int, a int, b int, c int) int {
    cnt,n:=0,len(arr)
    for i:=0;i<n-2;i+=1{
        for j:=i+1;j<n-1;j+=1{
            if abs(arr[i]-arr[j])<=a{
                for k:=j+1;k<n;k+=1{
                    if abs(arr[j]-arr[k])<=b && abs(arr[k]-arr[i])<=c{
                        cnt+=1
                    }
                }
            }
        }
    }
    return cnt    
}

func abs(x int)int{
    if x<0{
        return -x
    }
    return x
}