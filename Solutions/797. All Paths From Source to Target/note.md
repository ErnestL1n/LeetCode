## Either one can be used,I prefer the later one.The differnece is that I don't need to pass &path into function, since I don't need to get its change in main func,I just need its value

## Here is some useful link:
1. [Golang Pointer to an Array as Function Argument](https://www.geeksforgeeks.org/golang-pointer-to-an-array-as-function-argument/)
2. [Confusion about append and copy method](https://stackoverflow.com/questions/65368629/confusion-about-append-and-copy-method?noredirect=1#comment115573695_65368629)                         


### Useful comment: Python and Go are extremely different. In particular, in Python, ```l[:]``` does a copy operation (always); in Go, ```append``` sometimes copies the underlying array, and sometimes does not. That's really all there to this particular case: when Go copies, your code works, and when it (Go) doesn't, it (your code) doesn't 

```go
func allPathsSourceTarget(g [][]int) [][]int {
    var res [][]int
    var path []int
    path=append(path,0)
    dfs(g,&res,&path,0)
    return res
}

func dfs(g [][]int,res *[][]int,path *[]int,node int){
    if node==len(g)-1{
        tmp:=make([]int,len(*path))
        copy(tmp,*path)
        *res=append(*res,tmp)
    }
    for _,i:=range g[node]{
        *path=append(*path,i)
        dfs(g,res,path,i)
        *path=(*path)[:len(*path)-1]   
    }
}
```
```go
func allPathsSourceTarget(g [][]int) [][]int {
    var res [][]int
    var path []int
    path=append(path,0)
    dfs(g,&res,path,0)
    return res
}

func dfs(g [][]int,res *[][]int,path []int,node int){
    if node==len(g)-1{
        tmp:=make([]int,len(path))
        copy(tmp,path)
        *res=append(*res,tmp)
    }
    for _,i:=range g[node]{
        path=append(path,i)
        dfs(g,res,path,i)
        path=path[:len(path)-1]   
    }
}
```
