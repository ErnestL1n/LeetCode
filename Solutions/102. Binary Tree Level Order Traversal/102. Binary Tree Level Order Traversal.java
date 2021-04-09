/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        Queue<TreeNode> queue=new LinkedList<>();
        var res=new LinkedList<List<Integer>>();
        if(root==null)
            return res;
        queue.offer(root);
        while(!queue.isEmpty()){
            int levelNum=queue.size();
            var tmp=new ArrayList<Integer>();
            for(int i=0;i<levelNum;++i){
                if(queue.peek().left!=null)
                    queue.offer(queue.peek().left);
                if(queue.peek().right!=null)
                    queue.offer(queue.peek().right);
                tmp.add(queue.poll().val);
            }
         res.add(tmp);   
        }
        return res;
    }
}

//DFS
class Solution {
    private List<List<Integer>> res=new ArrayList<>();
    public List<List<Integer>> levelOrder(TreeNode root){
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
}