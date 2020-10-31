/**
 * 
 */
package github.com.ErnestL1n;

/**
 * @author https://github.com/ErnestL1n
 *
 */
import java.util.*;

//reference:
//NUS department of civil engineering
//CE 6001 operations management and infrastructure system
//https://stackoverflow.com/users/2741705/pham-trung


//only for complete direct graph
public class Traveling_Salesman_Problem_Dp {

	/**
	 * @param args
	 */
	
	public static ArrayList<Integer> outputArray=new ArrayList<Integer>();
	private static int g[][],path[][],dist[][],Npower,N;
	public static long time;
	
	public Traveling_Salesman_Problem_Dp() {
	};
	
	public static ArrayList<Integer> computeTSP(int[][] AdjMatrix,int n){
		long start=System.nanoTime();
		
		N=n;
		Npower=(int)Math.pow(2, N);
		dist=AdjMatrix;
		g=new int[N][Npower];
		path=new int[N][Npower];
		
		for(int i=0;i<N;i++)
			for(int j=0;j<Npower;j++) {
				g[i][j]=-1;
				path[i][j]=-1;
			}
		
		for(int i=0;i<N;i++)
			g[i][0]=dist[i][0];
				
		//start from vertex 0
		int result=tsp(0,(Npower-1)-1);
		outputArray.add(0);
		System.out.print("Optimal Tour is:");
		getPath(0,(Npower-1)-1);
		outputArray.add(0);
		outputArray.add(result);
		
		
		long end=System.nanoTime();
		
		time=(end-start)/1000;
		
		return outputArray;
	}
	
	private static int tsp(int start,int set) {
		int result=-1;
		int temp,masked,mask;
		if(g[start][set]!=-1) {
			return g[start][set];
		}
		else {
			for(int x=0;x<N;x++)
			{
				//Npow - 1 means all cities are visited,minus (1<<i), 
				//it means this is the state when all cities are visited, except city i
				mask=(Npower-1)-(1<<x);
				
				//g(i,S)=min{dist[i][k]+g(k,S-{k})}
				//this result All the visited cities in set will be 1, 
				//except if city i is already visited, it will be turned to 0.
				masked=mask&set;
				
				//which means, city i is 0 from the beginning (or unvisited).
				if(masked!=set) {
					temp=dist[start][x]+tsp(x,masked);
					if(result==-1||result>temp) {
						result=temp;
						path[start][set]=x;
					}
				}
			}
			
		}
		return g[start][set]=result;
	}
	
	private static void getPath(int start,int set) {
		if(path[start][set]==-1)return;
		int x=path[start][set];
		int mask=(Npower-1)-(1<<x);
		int masked=mask&set;
		outputArray.add(x);
		getPath(x,masked);
	}
	
	public static void main(String[] args) {
		
		
	    System.out.println("Enter number of cities");
	    Scanner keyboard=new Scanner(System.in);
		int n=keyboard.nextInt();
	    int npower=(int)Math.pow(2,n);//bit number required to represent all possible sets
	    System.out.println("Enter the adjacency matrix(Bidirected graph required)");
	    int[][] Adjmatrix=new int[n][npower];
	    for(int i=0;i<n;i++)
	        for(int j=0;j<n;j++)
	        	Adjmatrix[i][j]=keyboard.nextInt();
	    computeTSP(Adjmatrix,n);
	    for(int i=0;i<outputArray.size();i++) {
	    	if(i<outputArray.size()-2)
	    		System.out.print(outputArray.get(i)+"-->");
	    	else if(i==outputArray.size()-2)
	    		System.out.println(outputArray.get(i));
	    	else {
	    		System.out.println("Optimal Cost is:"+outputArray.get(i));
	    	}
	    }
	    System.out.println("Execution time is "+time+"£gs");
	    	
	}

}
