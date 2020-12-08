func permute(nums []int) [][]int {
    var res [][]int
    perm(nums,&res,0)
    return res
}
func perm(nums []int,res *[][]int,begin int){
    if len(nums)==begin{
        tmp:=make([]int,len(nums))
        copy(tmp,nums)
        *res=append(*res,tmp)
        return 
    }
    for i:=begin;i<len(nums);i+=1{
        nums[begin],nums[i]=nums[i],nums[begin]
        perm(nums,res,begin+1)
        nums[begin],nums[i]=nums[i],nums[begin]
    }
    return
}