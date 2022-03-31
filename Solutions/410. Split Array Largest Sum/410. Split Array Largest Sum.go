func splitArray(nums []int, m int) int {
    Max,sum:=0,0
    for _,n:=range(nums){
        Max=max(Max,n)
        sum+=n
    }
    if m==1{
        return sum
    }
    lo,hi:=Max,sum
    for lo<hi{
        mid:=(lo+hi)/2
        if count(nums,m,mid){
            hi=mid
        }else{
            lo=mid+1
        }
    }
    return lo
}

func count(nums []int,m,target_sum int) bool{
    cnt,sum:=1,0
    for _,n:=range(nums){
        sum+=n
        if sum>target_sum{
            sum=n
            cnt+=1
            if cnt>m{
                return false
            }
        }
    }
    return true
}

func max(i,j int) int {
    if i>j{
        return i
    }
    return j
}
