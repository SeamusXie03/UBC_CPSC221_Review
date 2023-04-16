
void clear(Node*& croot) {
	if (croot != NULL) {
		clear(croot->left);
		clear(croot->right);
		delete croot;
		croot = NULL;
	}
}

Node* copy(Node* croot) {
	Node* temp = NULL;
	if (croot != NULL) {
		temp = new Node(croot->data);
		temp->left = copy(croot->left);
		temp->right = copy(croot->right);
	}
	return temp;
}

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


/*------Binary Search Tree------*/

/* Θ(h)  =  Θ(n)*/
void insert (Node*& croot, const K & key){
	//croot passed by reference
	if (croot == NULL){
		croot = new Node (key);	
	}
	else if (key < croot->key){
		insert(croot->left, key);
	}
	else if (key > croot->key){
		insert(croot->right, key);
	}
}

/* Θ(n)*/
Node *& find (K& key, Node*& root){
	if (root == NULL){
		return NULL;
	}
	else if (root->key ==key){
		return root;
	}
	else if (root->key > key){
		return find(key, root->left);
	}
	else if (root->key < key){
		return find(key, root->right);
	}
}


void remove (Node*& root, const K& k){
	if (root != NULL){
		if (root->ley == k){
			doRemoval(root);
		}
		else if (k < root->key){
			remove(root->left, k);
		}
		else{
			remove(root->right, k);
		}
	}
}

void doRemoval(Node*& root){
	if (root->left != NULL && root->right != NULL){
		TwoChildRemove(root);
	}
	else{
		ZeroOneChildRemove(root);
	}
}


void TwoChildRemove(Node*& root){
	Node*& iop = rightMostChild (root->left);
	root->key = iop->key;
	zeroOneChildRemove(iop);
}


Node*& rightMostChild(Node*& root){
	if (root->right == NULL) return root;
	else return rightMostChild(root->right);
}

void zeroOneChildRemove(Node*& root){
	Node * temp = root;
	if (root->left == NULL) rppt = root->right;
	else root = root->left;
	delete temp;
}

