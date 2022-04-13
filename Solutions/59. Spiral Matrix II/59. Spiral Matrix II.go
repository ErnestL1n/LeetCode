func generateMatrix(n int) [][]int {
    r1,r2:=0,n-1
    c1,c2:=0,n-1
    val:=0
    res:=make([][]int,n)
    for i:=0;i<n;i+=1{
        res[i]=make([]int,n)
    }
    for r1<=r2 && c1<=c2{
        for i:=c1;i<=c2;i+=1{
            val+=1
            res[r1][i]=val;
        }
        for i:=r1+1;i<=r2;i+=1{
            val+=1
            res[i][c2]=val;
        }
        if r1<r2 && c1<c2{
            for i:=c2-1;i>c1;i-=1{
                val+=1
                res[r2][i]=val;
            }
            for i:=r2;i>r1;i-=1{
                val+=1
                res[i][c1]=val;
            }
        }
        r1,r2,c1,c2=r1+1,r2-1,c1+1,c2-1
    }
    return res;
}