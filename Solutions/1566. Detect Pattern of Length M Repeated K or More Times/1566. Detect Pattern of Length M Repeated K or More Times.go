func containsPattern(arr []int, m int, k int) bool {
    cnt:=0
    for i:=0;i+m<len(arr);i+=1{
        if arr[i]!=arr[i+m]{
            cnt=0
        }
        if arr[i]==arr[i+m]{
            cnt+=1
        }
        if cnt==(k-1)*m{
            return true
        }
    }
    return false
}