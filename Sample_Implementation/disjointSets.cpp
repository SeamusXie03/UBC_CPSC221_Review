// ------ Up Tree implementation ------
// the index if the variable, 
// which the value is the parent of curr

// Average Time: O(log(n))
// Worst Time: O(n)
int Find(int i) {
	// if the value at i is negative, we are at the root
	if (s[i] < 0) return [i];
	// else, go up once again to find the root
	else return Find(s[i]);
}

// Time: O(1)
int Union(int root1, int root2) {
	// make the root of root2 to be root 1;
	s[root2] = root1;
}

// Time: O(1)
// This one ensure the height of the tree is log(n)
int UnionBySize(int root1, int root2) {	
	// the root has the negative value of its height
	int newSize = s[root1] + s[root2];
	if (isBigger(root1, root2)) {
		// if the size of set1 is larger than set2, set2 points to set1
		s[root2] = root1;
		root1 = newSize;
	} else {
		// same if opposite happen
		s[root1] = root2;
		root2 = newSize;
	}
}
