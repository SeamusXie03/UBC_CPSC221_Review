
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
