// Average Time: O(n*logn)
// Best Time: O(n) 
void mergeSort(vector<T>& A, int lo, int hi) {
	// if the array has 0 or 1 elements, it is sorted, stop
	if (hi > lo) {
		// split the array to two different size
		int mid = (hi + lo)/2;
		// sort the lower part
		mergeSort(A, lo, mid);
		// sort the high part
		mergeSort(A, mid + 1, hi);
		// merge the sorted halves to produce one sorted result
		// Time: O(n)
		merge(A, lo, mid, hi);
	}
}
