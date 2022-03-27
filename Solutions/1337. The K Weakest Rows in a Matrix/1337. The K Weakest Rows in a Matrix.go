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
type MinHeap [][2]int
func (h MinHeap) Len() int{return len(h)}
func (h MinHeap) Less(i,j int) bool{if h[i][0]==h[j][0]{return h[i][1]<h[j][1]};return h[i][0]<h[j][0]}
func (h MinHeap) Swap(i,j int) {h[i],h[j]=h[j],h[i]}
func (h* MinHeap) Push(i interface{}){
    *h=append(*h,i.([2]int))
}
func (h* MinHeap) Pop() interface{}{
    v:=(*h)[len(*h)-1]
    *h=(*h)[:len(*h)-1]
    return v
}
func (h MinHeap) Peek() interface{}{
    return h[0]
}

func kWeakestRows(mat [][]int, k int) []int {
    pq:=&MinHeap{}
    heap.Init(pq)
    for i,m:=range(mat){
        heap.Push(pq,[2]int{numOnes(m),i})
    }
    var res []int
    fmt.Printf("%d",pq.Len())
    for k>0{
        res=append(res,pq.Peek().([2]int)[1])
        heap.Pop(pq)
        k-=1
    }
    return res
}

func numOnes(rows []int)int{
    lo,hi:=0,len(rows)-1
    for lo<=hi{
        mid:=(lo+hi)/2
        if rows[mid]==1{
            lo=mid+1
        }else{
            hi=mid-1
        }
    }
    return lo
}