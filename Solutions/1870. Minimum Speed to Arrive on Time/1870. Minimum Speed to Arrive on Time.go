func minSpeedOnTime(dist []int, hour float64) int {
    lo,hi,res,n:=1,10000000,-1,len(dist)
    for lo<=hi{
        mid:=(lo+hi)/2
        s:=0.0
        for i:=0;i<n-1;i+=1{
            s+=math.Ceil(float64(dist[i])/float64(mid))
        }
        s+=float64(dist[n-1])/float64(mid)
        if s>hour{
            lo=mid+1
        }else{
            hi=mid-1
            res=mid
        }
    }
    return res
}