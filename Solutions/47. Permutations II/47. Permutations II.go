func permuteUnique(nums []int) [][]int {
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
    s:=make(map[int]bool)
    for i:=begin;i<len(nums);i+=1{
        if _,ok:=s[nums[i]];!ok{
            nums[i],nums[begin]=nums[begin],nums[i]
            perm(nums,res,begin+1)
            nums[i],nums[begin]=nums[begin],nums[i]
            s[nums[i]]=true
        }
    }
    return
}