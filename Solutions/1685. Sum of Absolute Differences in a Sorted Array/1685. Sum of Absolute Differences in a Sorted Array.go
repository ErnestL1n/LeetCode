func getSumAbsoluteDifferences(nums []int) []int {
    n:=len(nums)
    res:=make([]int,n)
    prefix:=make([]int,n+1)
    for i:=0;i<n;i+=1{
        prefix[i+1]=prefix[i]+nums[i]
    }
    for i:=0;i<n;i+=1{
        res[i]=i * nums[i] - prefix[i] + (prefix[n] -  prefix[i] - (n - i) * nums[i]);
    }
    return res
}



// reduce (extra)space version
func getSumAbsoluteDifferences(nums []int) []int {
    n,leftsum,rightsum:=len(nums),0,sum(nums)
    res:=make([]int,n)
    for i:=0;i<n;i+=1{
        res[i]=i * nums[i] -leftsum + (rightsum - (n - i) * nums[i]);
        leftsum+=nums[i]
        rightsum-=nums[i]
    }
    return res
}
func sum(nums []int)int{
    s:=0
    for i:=0;i<len(nums);i+=1{
        s+=nums[i]
    }
    return s
}