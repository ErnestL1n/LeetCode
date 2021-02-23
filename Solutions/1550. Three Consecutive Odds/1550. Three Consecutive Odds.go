func threeConsecutiveOdds(arr []int) bool {
    cnt:=0
    for i:=range(arr){
        if arr[i]%2==0{
            cnt=0
        }else{
            cnt+=1
            if cnt==3{
                return true
            }
        }
    }
    return false
}