func maxProfit(prices []int) int {
    res:=0
    for i:=1;i<len(prices);i+=1{
        tmp:=prices[i]-prices[i-1]
        if tmp>0{
            res+=tmp
        }
    }
    return res
}