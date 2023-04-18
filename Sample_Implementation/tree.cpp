// Time: O(n)
void clear(Node*& croot) {
	if (croot != NULL) {
		clear(croot->left);
		clear(croot->right);
		delete croot;
		croot = NULL;
	}
}

// Time: O(n)
Node* copy(Node* croot) {
	Node* temp = NULL;
	if (croot != NULL) {
		temp = new Node(croot->data);
		temp->left = copy(croot->left);
		temp->right = copy(croot->right);
	}
	return temp;
}

// Time: O(n)
void levelOrder(Node* croot) {
	queue<Node*> Q;
	Q.push(croot);
	while (!Q.isempty*()) {
		Node* t = Q.front();
		Q.pop();
		// if this node is not NULL, enqueue all its child
		if (t) {
			yell t;
			Q.push(t->left);
			Q.push(t->right);
		}
	}
}

/*AVL Tree*/

void insert (const T& x, treeNode<t>*& t){
	if (t == NULL) t = new treeNode<T>(x,0,NULL,NULL);
	    //key, height, keft cihld, right child
	else if (x < t->key){
		insert(x, t->left);
		int balance = height(t->right) - height(t->left);
		int leftBalance = height(t->left->right) - height(t->left->left);
		if(balance == -2){
			if (leftBalnce == -1)	rotate_right(t);
			else rotate_left_right(t);
		}
	else if (x > t->key){
		insert(x, t->right);
		int balance = height(t->right) - height(t->left);
		int rightBalance = height(t->right->right) - height(t->right->left);
		if(balance == 2){
			if (leftBalnce == 1)	rotate_left(t);
			else rotate_right_left(t);
		}
	//update the height of the inserted node
	t->height = max(height(t->left), height(t->right));
	}
}
