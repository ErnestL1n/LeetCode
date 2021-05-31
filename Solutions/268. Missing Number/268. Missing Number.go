func missingNumber(nums []int) int {
    res,i:=len(nums),0
    for i<len(nums){
        res+=i-nums[i]
        i+=1
    }
    return res
}

func missingNumber(nums []int) int {
    res,i:=len(nums),0
    for i<len(nums){
        res^=i^nums[i]
        i+=1
    }
    return res
}