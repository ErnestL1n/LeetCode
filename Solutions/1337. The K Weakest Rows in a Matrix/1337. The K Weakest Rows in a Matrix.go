// sort with 2D slice
// using sort O(max(mn,nlogn))
func kWeakestRows(mat [][]int, k int) []int {
    tmp:=make([][]int,len(mat))
    for i,x:=range(mat){
        tmp[i]=make([]int,2)
        for _,y:=range(x){
            if y==1{
                tmp[i][0]+=1
            }
        }
        tmp[i][1]=i
    }
    var res []int
    sort.Slice(tmp,func(i,j int)bool{
        if len(tmp[i])==0 && len(tmp[j])==0{
            return false
        }
        if len(tmp[i])==0 || len(tmp[j])==0{
            return len(tmp[i])==0
        }
        if tmp[i][0]==tmp[j][0]{
            return tmp[i][1]<tmp[j][1]
        }
        return tmp[i][0]<tmp[j][0]
    })
    for i:=0;k>0;i,k=i+1,k-1{
        res=append(res,tmp[i][1])
    }
    return res
}

// priority queue + binary search O(m*(logn+logk))=O(m*log(max(n, k))