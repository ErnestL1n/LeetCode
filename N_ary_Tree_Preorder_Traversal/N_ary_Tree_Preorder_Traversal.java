/**
 * 
 */
package github.com.ErnestL1n;
import java.util.*;
/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.589
class Node{
	int val;
	List<Node> children;
	
	public Node() {}

    public Node(int _val) {
    	this.val = _val;
    	this.children=new LinkedList<>();
    	}

    public Node(int _val, List<Node> _children) {
    	this.val = _val;
    	this.children = _children;
    	}
}
public class N_ary_Tree_Preorder_Traversal {

	/**
	 * @param args
	 */
	
	public static Node BuildTree(Integer[] nodes) {
		//Integer[] nodes=new Integer[] {1,null,3,2,4,null,5,6};
		if(nodes==null||nodes.length==0)return null;
		Queue<Node> treenodequeue=new LinkedList<>();
		Queue<Integer> integerqueue=new LinkedList<>();
		Node root=new Node(nodes[0]);
		treenodequeue.offer(root);
		for(int i=1;i<nodes.length;i++)integerqueue.offer(nodes[i]);
		while(!integerqueue.isEmpty()){
			Node current=treenodequeue.poll();
			integerqueue.remove(null);
			while(integerqueue.peek()!=null) {
				Integer tempvalue=integerqueue.poll();
				Node tempnode=new Node(tempvalue);
				current.children.add(tempnode);
				treenodequeue.offer(tempnode);
			}
		}
		return root;
	}
	
	public static int getTreeSize(Node root) {
		if(root==null)return 0;
		int totalcount=1;
		Queue<Node> queue=new LinkedList<>();
		queue.offer(root);
		while(!queue.isEmpty()) {
			Node current=queue.poll();
			if(current.children.size()!=0) {
				totalcount+=current.children.size();
				queue.addAll(current.children);
			}
		}
		return totalcount;
	}
	
	
	
	
	public static void printTree(Node root) {
		if(root==null)return;
		Queue<Node> treenodequeue=new LinkedList<>();
		int size=getTreeSize(root);
		treenodequeue.offer(root);
		System.out.println("I am root , my value is "+root.val);
		size--;
		while(size!=0) {
			int index=1;
			Node current=treenodequeue.poll();
			for(int i=0;i<current.children.size();i++){
				System.out.println("I am "+index+"th child of "+current.val+" , my value is "+current.children.get(i).val);
				index++;
				size--;
				treenodequeue.offer(current.children.get(i));
			}
		}
	}
	
	
	//recursive solution
	private static List<Integer> answer=new ArrayList<>();
	public static List<Integer> preorderRecursive(Node root) {
	        if(root==null)return answer;
	        answer.add(root.val);
	        List<Node> children=root.children;
	        for (int i = 0; i < children.size(); i++)
	        	preorderRecursive(children.get(i));
	        return answer;
	    }
	
	//Iterative solution
	//Iterative version is using stack
	//preorder=>push rightmost child into stack first
	public static List<Integer> preorderIterative(Node root){
        List<Integer> res=new ArrayList<>();
        if(root==null)return res;
        Stack<Node> stk=new Stack<>();
        stk.push(root);
        while(!stk.isEmpty()){
            Node curr=stk.pop();
            res.add(curr.val);
            for(int i=curr.children.size()-1;i>=0;--i)
                if(curr.children.get(i)!=null)
                    stk.push(curr.children.get(i));
        }
        return res;
	}

	
	public static void main(String[] args) {
		Integer[] nodes=new Integer[] {1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14};
		System.out.println("Given an n-ary tree :"+Arrays.toString(nodes));
		Node root=BuildTree(nodes);
		printTree(root);
		System.out.println("\nreturn the preorder traversal of its nodes' values");
		System.out.println("\nNary-Tree input serialization is represented in their level order traversal,");
		System.out.println ("each group of children is separated by the null value\n");
		System.out.println("Thus the preorder traversal is "+preorderIterative(root));
        
	}

}
