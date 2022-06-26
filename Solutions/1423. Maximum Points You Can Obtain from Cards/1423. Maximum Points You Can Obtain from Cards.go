func maxScore(cardPoints []int, k int) int {
    n,lsum:=len(cardPoints),0
    for i:=0;i<k;i+=1{
        lsum+=cardPoints[i]
    }
    mx,rsum:=lsum,0
    for i:=0;i<k;i+=1{
        rsum+=cardPoints[n-1-i]
        lsum-=cardPoints[k-1-i]
        mx=max(mx,lsum+rsum)
    }
    return mx
}

func max (i,j int) int{
    if i>j{
        return i
    }
    return j
}