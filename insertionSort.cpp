
// The overall running time for this algorithm is n^2
void insertionSort (vector<string> & candy) {
	// running time is n
	for (int i = 1; i < candy.size(); i++) slide(candy ,i);
}

// running time is n
void slide (vector<string> & candy, int loc) {
	// save the current key on the stack
	string temp = candy[loc];
	int j = loc;
	// if we are not at the beginning and 
	// they are still element bigger than the current element
	while (j > 0 && candy[j-1] > temp) {
		// move the larger element one position up
		candy[j] = candy[j-1];
		// go to the previous location
		j--;
	}
	// put the current key into the right position
	candy[j] = temp;
}
