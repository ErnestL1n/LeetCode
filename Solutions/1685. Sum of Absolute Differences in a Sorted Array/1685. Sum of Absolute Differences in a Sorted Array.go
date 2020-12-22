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