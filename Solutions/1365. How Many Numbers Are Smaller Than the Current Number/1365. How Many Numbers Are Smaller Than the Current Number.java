//count
class Solution {
	public int[] smallerNumbersThanCurrent(int[] nums) {
		int[] res=new int[nums.length];
		int[] cnt=new int[101];
		for(int n:nums)++cnt[n];
		for(int i=1;i<=100;i++)cnt[i]+=cnt[i-1];
		for(int i=0;i<nums.length;++i) {
			if(nums[i]==0)res[i]=0;
			else res[i]=cnt[nums[i]-1];
		}
		return res;
	}
}

//hashmap
class Solution {
	public static int[] smallerNumbersThanCurrent(int[] nums) {
		HashMap<Integer,Integer> map=new HashMap<>();
		int[] temp=nums.clone();
		Arrays.sort(temp);
		for(int i=0;i<nums.length;++i)map.putIfAbsent(temp[i], i);
		for(int i=0;i<nums.length;++i)temp[i]=map.get(nums[i]);
		return temp;
	}
}