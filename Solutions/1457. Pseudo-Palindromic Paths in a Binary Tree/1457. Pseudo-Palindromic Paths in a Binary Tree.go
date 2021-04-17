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
    odds,res:=0,0
    dfs(root,&cnt,&odd,&res)
    return res
}
func dfs(root *TreeNode,cnt *[]int,odd,res *int) {
    if root!=nil{
        (*cnt)[root.Val]+=1
        if (*cnt)[root.Val]%2==1{
            *(odd)+=1
        }else{
            *(odd)-=1
        }
        if root.Left==root.Right{
            if *(odd)<2{
                *(res)=1
            }else{
                *(res)=0
            }
        }else{
            res=dfs(root.Left,cnt)+dfs(root.Right,cnt)
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