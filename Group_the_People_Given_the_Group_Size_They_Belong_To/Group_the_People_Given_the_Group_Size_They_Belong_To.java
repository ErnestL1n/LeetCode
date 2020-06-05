/**
 * 
 */
package github.com.ErnestL1n;
import java.util.*;
/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.1282
public class Group_the_People_Given_the_Group_Size_They_Belong_To {

	/**
	 * @param args
	 */
	public static List<List<Integer>> groupThePeople(int[] groupSizes){
		int size=groupSizes.length;
		HashMap<Integer,List<Integer>> map=new HashMap<>();
		//to be returned
		List<List<Integer>> answer=new ArrayList<>();
		
		for(int i=0;i<size;i++) {
			int current=groupSizes[i];
			
			//[] for each group
			List<Integer> temp=new ArrayList<>();
			//get(current) => return List<Integer>,finding the set at temp[k]
			if(map.containsKey(current))temp=map.get(current);
			//add into new temp[k]
			temp.add(i);
			
			//update map
			map.put(current, temp);
			if(temp.size()==current) {
				answer.add(temp);
				//remove key
				map.remove(current);
			}
			
		}
		return answer;
		
	}
	public static void main(String[] args) {
		int[] groupSizes1=new int[] {3,3,3,3,3,1,3};
		int[] groupSizes2=new int[] {2,1,3,3,3,2};
		System.out.println("Input: groupSizes = "+Arrays.toString(groupSizes1));
		System.out.println("Output is "+groupThePeople(groupSizes1));
		System.out.println("Input: groupSizes = "+Arrays.toString(groupSizes2));
		System.out.println("Output is "+groupThePeople(groupSizes2));

	}

}
