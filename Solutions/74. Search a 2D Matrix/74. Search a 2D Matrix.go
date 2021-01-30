func searchMatrix(mat [][]int, target int) bool {
    m,n:=len(mat),len(mat[0])
    l,r:=0,m*n-1
    for l<=r{
        mid:=(l+r)/2
        if mat[mid/n][mid%n]==target{
            return true
        }
        if mat[mid/n][mid%n]<target{
            l=mid+1
        }else{
            r=mid-1
        }
    }
    return false
}