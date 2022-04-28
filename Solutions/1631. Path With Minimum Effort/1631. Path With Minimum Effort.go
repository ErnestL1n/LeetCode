type MinHeap [][3]int
func (h MinHeap) Len() int {
    return len(h)
}
func (h MinHeap) Less (i,j int) bool {
    return h[i][0]<h[j][0]
}
func (h MinHeap) Swap (i,j int) {
    h[i],h[j]=h[j],h[i]
}
func (h *MinHeap) Push(i interface{}) {
    *h=append(*h,i.([3]int))
}
func (h *MinHeap) Pop() interface{} {
    v:=(*h)[len(*h)-1]
    *h=(*h)[:len(*h)-1]
    return v
}

func minimumEffortPath(heights [][]int) int {
    var dirs=[4][2]int{{0,1},{0,-1},{1,0},{-1,0}}
    m,n:=len(heights),len(heights[0])
    dist:=make([][]int,m)
    for i:=0;i<m;i+=1{
        dist[i]=make([]int,n)
        for j:=0;j<n;j+=1{
            dist[i][j]=math.MaxInt64
        }
    }
    pq:=&MinHeap{}
    heap.Init(pq)
    heap.Push(pq,[3]int{0,0,0})
    for pq.Len()>0 {
        cur:=heap.Pop(pq).([3]int)
        d,r,c:=cur[0],cur[1],cur[2]
        if d>dist[r][c]{
            continue
        }
        if r==m-1 && c==n-1 {
            return d
        }
        for _,dir:=range dirs{
            x,y:=dir[0]+r,dir[1]+c
            if x>=0 && x<m && y>=0 && y<n{
                tmp:=max(d,abs(heights[x][y]-heights[r][c]))
                if dist[x][y]>tmp{
                    dist[x][y]=tmp;
                    heap.Push(pq,[3]int{tmp,x,y})
                }
            }
        }
    }
    return -1
}

func max (i,j int) int{
    if i>j{
        return i
    }
    return j
}

func abs (i int) int{
    if i<0{
        return -i
    }
    return i
}