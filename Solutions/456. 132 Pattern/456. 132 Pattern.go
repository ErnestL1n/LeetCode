func find132pattern(nums []int) bool {
    z:=math.MinInt64
    var stk []int
    for i:=len(nums)-1;i>=0;i-=1{
        if nums[i]<z{
            return true
        }else{
            for len(stk)>0 && nums[i]>stk[len(stk)-1]{
                z=stk[len(stk)-1];stk=stk[:len(stk)-1]
            }
            stk=append(stk,nums[i])
        }
    }
    return false
}