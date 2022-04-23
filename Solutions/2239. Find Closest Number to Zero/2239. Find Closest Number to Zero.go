func findClosestNumber(nums []int) int {
    res:=nums[0]
    for i:=1;i<len(nums);i+=1{
        if abs(nums[i])<abs(res){
            res=nums[i]
        }else if abs(nums[i])==abs(res) && nums[i]>res{
            res=nums[i]
        }
    }
    return res
}

func abs(x int) int {
    if x<0{
        return -x
    }
    return x
}