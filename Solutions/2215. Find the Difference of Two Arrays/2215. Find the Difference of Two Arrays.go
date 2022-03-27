func findDifference(nums1 []int, nums2 []int) [][]int {
    s1,s2:=make(map[int]bool),make(map[int]bool)
    for _,n:=range(nums1){
        s1[n]=true
    }
    for _,n:=range(nums2){
        s2[n]=true
    }
    res:=make([][]int,2)
    for k,_:=range s1{
        if _,ok:=s2[k];!ok{
            res[0]=append(res[0],k)
        }
    }
    for k,_:=range s2{
        if _,ok:=s1[k];!ok{
            res[1]=append(res[1],k)
        }
    }
    return res
}