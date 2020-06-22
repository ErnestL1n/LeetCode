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
    	val = _val;
    	}

    public Node(int _val, List<Node> _children) {
    	val = _val;
    	children = _children;
    	}
}
public class N_ary_Tree_Preorder_Traversal {

	/**
	 * @param args
	 */
	
	
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
	public List<Integer> preorderIterative(Node root){
	    List<Integer> answer=new ArrayList<>();
	    if(root==null)return answer;
	    Stack<Node> stack=new Stack<>();
	    stack.push(root);
	    while(!stack.isEmpty()){
	        Node current=stack.pop();
	        answer.add(current.val);
	        List<Node> childs = current.children;
	        int size = childs.size() - 1;
	        while (!childs.isEmpty()) {
	            //push method will give them a clue that they're using the Stack
	            stack.push(childs.remove(size));
	            size--;
	        }
	    }
	    return answer;
	}
	
	public static void main(String[] args) {
		

	}

}
