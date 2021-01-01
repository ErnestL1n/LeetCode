func heightChecker(heights []int) int {
    res,currh:=0,0
    cnt:=make([]int,101)
    for _,h:=range(heights){
        cnt[h]+=1
    }
    for _,h:=range(heights){
        for cnt[currh]==0{
            currh+=1
        }
        if currh!=h{
            res+=1
        }
        cnt[currh]-=1
    }
    return res
}