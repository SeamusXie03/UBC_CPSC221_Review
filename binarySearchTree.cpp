// Avg Time: O(h)
// Worst Time: O(n)
void insert(Node*& croot, const K & key) {
	if (croot == NULL) {
		croot = new Node(key);
	} else if (key < croot->key) {
		insert(croot->left);
	} else if (key > croot->key) {
		insert(croot->right);
	}
	// if key == croot->key, nothing happens, since we want to maintain uniqueness
}

// Avg Time: O(h)
// Worst Time: O(n)
Node*& find(K & key, Node*& r) {
	if (r == NULL) return NULL;
	else if (r->key == key) return r;
	else if (r->key < key) find(r->left, key);
	else find(r->right, key);
}

// Avg Time: O(h)
// Worst Time: O(n)
void remove(Node*& croot, const K & k) {
	if (croot != NULL) {
		if (croot->key == key) {
			doRemoval(croot);
		} else if (k < croot->key) {
			remove(croot->left, k);
		} else {
			remove(croot->right, k);
		}
	}
}

// Avg Time: O(h)
// Worst Time: O(n)
void doRemoval(Node*& croot) {	
	if ((croot->left != NULL) && (croot->left != NULL)) {
		// if there are two child, we need to maintain the in order traversal
		twoChildRemove(croot);
	} else {
		// if there is only one child, we just need to fix the pointer
		zeroOneChildRemove(croot);
	}
}

void zeroOneChildRemove(Node*& croot) {
	Node* temp = croot;
	if (croot->left == NULL) croot = croot->right;
	else croot = croot->left;
	delete temp;
}

void twoChildRemove(Node*& croot) {
	// find the right most child of the left subtree
	Node*& iop = rightMostChild(croot->left);
	// change the key in the croot
	croot->key = iop->key;
	// remove this child to avoid duplicate
	zeroOneChildRemove(iop);
}

Node*& rightMostChild(Node*& root){
	// if there is no more right child, return this root
	if (root->right == NULL) return root;
	// if we are not yet at the end, continue finding 
	else return rightMostChild(root->right);
}
