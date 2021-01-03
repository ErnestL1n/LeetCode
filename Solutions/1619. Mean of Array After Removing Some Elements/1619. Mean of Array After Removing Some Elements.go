func trimMean(arr []int) float64 {
    sort.Ints(arr)
    sum,count:=0,0
    size:=len(arr)
    for i:=size/20;i<size-size/20;i+=1{
        count+=1
        sum+=arr[i]
    }
    return float64(sum)/float64(count)
}