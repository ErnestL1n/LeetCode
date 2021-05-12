func subsets(nums []int) [][]int {
    var res [][]int
    var tmp []int
    foo(nums,&res,tmp,0)
    return res
}
func foo(nums []int,res *[][]int,tmp []int,begin int){
    t:=make([]int,len(tmp))
    copy(t,tmp)
    (*res)=append(*res,t)
    for i:=begin;i<len(nums);i+=1{
        tmp=append(tmp,nums[i])
        foo(nums,res,tmp,i+1)
        tmp=tmp[:len(tmp)-1]
    }
}