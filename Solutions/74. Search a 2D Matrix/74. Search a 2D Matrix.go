func searchMatrix(mat [][]int, target int) bool {
    m,n:=len(mat),len(mat[0])
    lo,hi:=0,m*n-1
    for lo<=hi{
        mid:=(lo+hi)/2
        if mat[mid/n][mid%n]==target{
            return true
        }
        if mat[mid/n][mid%n]<target{
            lo=mid+1
        }else{
            hi=mid-1
        }
    }
    return false
}