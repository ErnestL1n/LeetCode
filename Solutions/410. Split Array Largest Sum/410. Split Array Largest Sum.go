func splitArray(nums []int, m int) int {
    Max,sum:=0,0
    for _,num:=range(nums){
        Max=max(num,Max)
        sum+=num
    }
    if m==1{
        return sum
    }
    l,r:=Max,sum
    for l<=r{
        mid:=(l+r)/2
        if(valid(nums,mid,m)){
            r=mid-1
        }else{
            l=mid+1
        }
    }
    return l
}
func valid(nums []int,mid,m int) bool {
    cnt,total:=1,0
    for _,num:=range(nums){
        total+=num
        if total>mid{
            total=num
            cnt+=1
            if cnt>m{
                return false
            }
        }
    }
    return true
}
func max(i,j int) int {
    if(i>j){
        return i
    }
    return j
}