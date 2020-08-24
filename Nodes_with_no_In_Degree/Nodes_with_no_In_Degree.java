/**
 * 
 */
package github.com.ErnestL1n;
import java.util.*;
/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.1557
public class Nodes_with_no_In_Degree {

	/**
	 * @param args
	 */
	public List<Integer> findSmallestSetOfVertices(int n, List<List<Integer>> edges){
		var res=new ArrayList<Integer>();
		int[] seen=new int[n];
		for(List<Integer> e:edges)
			seen[e.get(1)]=1;
		for(int i=0;i<n;++i)
			if(seen[i]==0)
				res.add(i);
		return res;
	}
	public static void main(String[] args) {
	}

}
