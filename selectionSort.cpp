
// Average Time: O(n^2)
// Best TimeL O(n^2)
void selection_sort (vector<string> & candy) {
	// the outter loop runs for n times
	for (int i = 0; i < candy.size(); i++) {
		// findMin runs for n times
		int min = findMin(candy, i);
		// constant time
		swap(candy, min, i);
	}
}
