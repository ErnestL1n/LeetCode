func minOperations(nums []int, x int) int {
    target:=-x;
    for _,num:=range nums{
        target+=num
    }
    if target==0{
        return len(nums)
    }
    m:=make(map[int]int)
    m[0]=-1;
    sum,res:=0,math.MinInt

    for i:=0;i<len(nums);i+=1{
        sum+=nums[i];
        if _,ok:=m[sum-target];ok{
            res=max(res,i-m[sum-target]);
        }
        m[sum]=i;
    }
    if res==math.MinInt{
        return -1
    }else{
        return len(nums)-res
    }
}

func max(i,j int) int{
    if i>j{
        return i
    }
    return j
}