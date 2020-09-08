/**
 * @author https://github.com/ErnestL1n
 *
 */
 //Leetcode.102
 import java.util.*;
public class Binary_Tree_Level_Order_Traversal {
    public List<List<Integer>> levelOrder(TreeNode root) {
        Queue<TreeNode> queue=new LinkedList<>();
        var res=new LinkedList<List<Integer>>();
        if(root==null)
            return res;
        queue.offer(root);
        while(!queue.isEmpty()){
            int levelNum=queue.size();
            var sublist=new ArrayList<Integer>();
            for(int i=0;i<levelNum;++i){
                if(queue.peek().left!=null)
                    queue.offer(queue.peek().left);
                if(queue.peek().right!=null)
                    queue.offer(queue.peek().right);
                sublist.add(queue.poll().val);
            }
         res.add(sublist);   
        }
        return res;
    }
    
    //dfs version
    private List<List<Integer>> res=new ArrayList<>();
    public List<List<Integer>> levelOrderDFS(TreeNode root){
        dfs(root,0);
        return res;
    }
    private void dfs(TreeNode root,int depth){
        if(root==null)
        return;
        if(res.size()==depth)
        res.add(new ArrayList<>());
        res.get(depth).add(root.val);
        dfs(root.left,depth+1);
        dfs(root.right,depth+1);
    }
    

    
    public static void main(String[] args){

    }
}
