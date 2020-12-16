# Golang
### If I do this, Begin is declared before everything and it doesn't always initialize as ```nil``` 
### [answer to solve the problem](https://stackoverflow.com/questions/65310014/why-my-code-cant-pass-the-leetcode-submission-while-the-same-test-case-in-run)

```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

var Begin *TreeNode=nil

func findTarget(root *TreeNode, k int) bool {
    if(Begin==nil){
        Begin=root
    }
    if(root==nil){
        return false
    }
    if(search(root,k-root.Val)==true){
        return true
    }
    return findTarget(root.Left,k) || findTarget(root.Right,k)
}

func search(node *TreeNode,complement int) bool{
    var curr *TreeNode=Begin
    for curr!=nil{
        if(complement>curr.Val){
            curr=curr.Right
        }else if(complement<curr.Val){
            curr=curr.Left
        }else{
            if(curr==node){
                return false
            }else{
                return true
            }
        }
    }
    return false
}
```
