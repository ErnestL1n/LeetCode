class Solution {
    public double trimMean(int[] arr) {
        Arrays.sort(arr);
        double sum=0;
        int count=0,size=arr.length;
        for (int i = size / 20; i < size - (size / 20); ++i) {
		sum += arr[i];
		++count;
	}
        return sum / count;
    }
}