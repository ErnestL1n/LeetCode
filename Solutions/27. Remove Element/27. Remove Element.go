func removeElement(nums []int, val int) int {
    begin:=0
    for i:=0;i<len(nums);i+=1{
        if nums[i]!=val{
            nums[begin]=nums[i]
            begin+=1
        }
    }
    return begin
}