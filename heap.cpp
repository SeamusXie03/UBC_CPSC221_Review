// ------ Min-Heap implementation ------
// For some reason, we use index 1 as the root
// and we use size as the last index of the array

int leftChild(int parent) {
	return 2 * parent;
}

int rightChild(int parent) {
	return 2 * parent + 1;
}

int parent(int child) {
	return child / 2;
}

bool hasAChild(int parent) {
	return leftChild(parent) <= size;
}

int minChild(int parent) {
	if (rightChild(parent) <= size) 
		return items[leftChild(parent)] <= items[rightChild(parent)] ? leftChild(parent) : rightChild(parent);
	return leftChild(parent);
}

void swap(T& left, T& right) {
	T temp = left;
	left = right;
	right = temp;
}

// Time: O(log(n)) = O(h)
void insert(const T & key) {
	if (size == capacity) growAway();
	size+;
	items[size] = key;
	heapifyUp(size);
}

// Time: O(log(n)) = O(h)
void heapifyUp(int curr) {
	if (curr > 1) {
		// if we are not at the root
		if (items[curr] < items[parent(curr)]) {
			// if the child is smaller than the parent, we swap
			swap(items[curr], items[parent(curr)]);
			// go up one layer to check once again
			heapifyUp(parent(curr));
		}
	}
}

T removeMin() {
	// give the root to the user
	T minVal = items[1];
	// pick the leaf to the root
	items[1] = items[size];
	size--; // remove the leaf fromt the array
	heapifyDown(int curr);
	return minVal;
}

// Time: O(log(n)) = O(h)
void heapifyDown(int curr) {
	// find if this curr has a child
	if (hasAChild(curr)) {
		minChildIndex = minChild(curr);
		if (items[curr] > items[minChildIndex]) {
			swap(items[curr], items[minChildIndex]);
			heapifyDown(minChildIndex);
		}
	}
}

// Time: O(nlog(n))
// incremented insertion
void buildHeap() {
	for (int i = 2; i <= size; i++) 
		heapifyUp(i);
}

// Time: O(n)
// decremented insertion
void buildHeap() {
	for (int i = parent(size); i > 0; i--) 
		heapifyDown(i);
}
