// Time: O(h)
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

// Time: O(h)
Node*& find(K & key, Node*& r) {
	if (r == NULL) return NULL;
	else if (r->key == key) return r;
	else if (r->key < key) find(r->left, key);
	else find(r->right, key);
}

// Time: O(h)
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

// Time: O(h)
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
	croot->key = iop->key;
	zeroOneChildRemove(iop);
}
