/**
 * 
 */
package github.com.ErnestL1n;
import java.util.*;
/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.1436
public class Destination_City {

	/**
	 * @param args
	 */
	//this is 2ms solution published by https://leetcode.com/hobiter/
	/*
	public static String destCity(List<List<String>> paths) {
		HashMap<String,Boolean> map=new HashMap<>();
		for(List<String> city:paths) {
			//if city isn't destination, set its value as false, else,true
			map.put(city.get(0),false);
			if(!map.containsKey(city.get(1)))map.put(city.get(1),true);
		}
		for(String city:map.keySet())
			if(map.get(city))return city;
		return null;
	}*/
	/*A more straightforeward method reduced this problem to 1 ms */
	public static String destCity(List<List<String>> paths) {
		HashMap<String,String> map=new HashMap<>();
		for(List<String> city:paths)
			map.put(city.get(0), city.get(1));
		for(String dest:map.values())if(map.get(dest)==null)return dest;
		return null;
	}
	public static void main(String[] args) {
		String[] cities=new String[]{"London","New York","New York","Lima","Lima","Sao Paulo"};
		List<List<String>> paths=new ArrayList<>();
		for(int i=0;i<cities.length;i+=2)paths.add(Arrays.asList(cities[i],cities[i+1]));
		System.out.println("City pairs are "+paths);
		System.out.println("the destination city is "+destCity(paths));
		
		

	}

}
