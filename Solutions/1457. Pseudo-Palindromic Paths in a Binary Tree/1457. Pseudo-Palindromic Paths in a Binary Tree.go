/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func pseudoPalindromicPaths (root *TreeNode) int {
    cnt:=make([]int,10)
    return dfs(root,&cnt,0)
}
func dfs(root *TreeNode,cnt *[]int,odds int) int{
    res:=0
    if root!=nil{
        (*cnt)[root.Val]+=1
        if (*cnt)[root.Val]%2==1{
            odds+=1
        }else{
            odds-=1
        }
        if root.Left==nil &&root.Right==nil{
            if odds<2{
                res=1
            }else{
                res=0
            }
        }else{
            res=dfs(root.Left,cnt,odds) + dfs(root.Right,cnt,odds) 
        }
        (*cnt)[root.Val]-=1
        if (*cnt)[root.Val]%2==1{
            odds-=1
        }else{
            odds+=1
        }
    }
    return res
}