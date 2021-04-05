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
//BFS , level order traversal
class Solution {
    public int maxLevelSum(TreeNode root) {
        int maxsum=Integer.MIN_VALUE,level=0,maxlevel=0;
        Queue<TreeNode> q=new LinkedList<>();
        q.offer(root);
        while(q.size()>0){
            ++level;
            int sum=0,qsz=q.size();
            while(qsz>0){
                --qsz;
                var tmp=q.poll();
                sum+=tmp.val;
                if(tmp.left!=null)
                    q.offer(tmp.left);
                if(tmp.right!=null)
                    q.offer(tmp.right);
            }
            if(maxsum<sum){
                maxsum=sum;
                maxlevel=level;
            }
        }
        return maxlevel;
    }
}


	
//DFS
class Solution {
    List<Integer> list=new ArrayList<>();
    public int maxLevelSum(TreeNode root) {
        dfs(root,0);
        int maxlevel=0;
        for(int i=0;i<list.size();++i)
            if(list.get(i)>list.get(maxlevel))
                maxlevel=i;
        return maxlevel+1;
    }
    private void dfs(TreeNode root,int level){
        if(root==null)return;
        if(level==list.size())list.add(root.val);
        else list.set(level,list.get(level)+root.val);
        dfs(root.left,level+1);
        dfs(root.right,level+1);
    }
}

	

