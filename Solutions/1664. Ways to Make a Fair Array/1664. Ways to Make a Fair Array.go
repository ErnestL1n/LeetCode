func waysToMakeFair(nums []int) int {
    l,r,res:=[2]int{},[2]int{},0
    for i:=0;i<len(nums);i+=1{
        r[i%2]+=nums[i]
    }
    for i:=0;i<len(nums);i+=1{
        r[i%2]-=nums[i]
        if x,y:=r[0]+l[1],r[1]+l[0];x==y{
            res+=1
        }
        l[i%2]+=nums[i]
    }
    return res
}