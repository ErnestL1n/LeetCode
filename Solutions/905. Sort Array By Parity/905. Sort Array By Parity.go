func sortArrayByParity(nums []int) []int {
    for i,j:=0,0;j<len(nums);j+=1{
        if nums[j]%2==0{
            nums[i],nums[j]=nums[j],nums[i]
            i+=1
        }
    }
    return nums
}