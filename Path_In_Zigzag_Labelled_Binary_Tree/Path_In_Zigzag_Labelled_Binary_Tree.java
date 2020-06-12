/**
 * 
 */
package github.com.ErnestL1n;
import java.util.*;
/**
 * @author https://github.com/ErnestL1n
 *
 */
//reference:https://leetcode.com/umn-hkc/
//Leetcode.1104
public class Path_In_Zigzag_Labelled_Binary_Tree {

	/**
	 * @param args
	 */
	public static List<Integer> pathInZigZagTree(int label){
		//We know that the target node's actual parent should be the parent of its symmetric node at current height.
		LinkedList<Integer> answer=new LinkedList<>();
		int level=0;
		//we first get the current height which is the first whlie loop
		while(1<<level<=label)++level;
		//Then, to get the symmetric node, we first need to realize the fact:
		//(label of current node + label of symmetric node) == (label of minimum node at current height) 
		//+ (label of maximum node at current height)
		
		//The minimum label can be calculated by 2^(level - 1) and
		//maximum label can be calculated by 2^(level) - 1, where level is the current height.
		while(label!=0) {
			answer.addFirst(label);
			label=((1<<level)-1+(1<<(level-1))-label)/2;
			--level;
		}
		return answer;
	}
	public static void main(String[] args) {
		int label=26;
		System.out.println("Given label is :"+label);
		System.out.println("The labels in the path from the root of the tree to the node with that label are :");
		System.out.println(pathInZigZagTree(label));
		}
}

