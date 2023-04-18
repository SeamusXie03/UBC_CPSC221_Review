
// Time: O(n)
// Space: O(n)
Node* Find(Node* place, int k){
	// if we find the index, or if we are at the end, return;
	if ((k == 0) || (place == NULL)) return place;

	// else, go to the next layer
	return Find(place->next, k-1);
}

// Time: O(n)
// Space: O(n)
void list_insert(int loc, LIT e) {
	if (loc > 1) {
		Node* curr = Find(place->next, loc - 1);
		Node* newN = new Node(e);
		newN->next = curr->next;
		curr->next = newN;
	else {
		insertAtFront(head, e); 
	}
}

// Time: O(n)
// Space: O(1)
void removeCurrent(Node*& head, Node*& curr) {
	Node* w = head;
	if (w != curr) {
		// finding the pointer to the current node
		while (w->next != curr) w = w->next;
		w->next = curr->next;
	} else {
		// if this is the head,
		// we just need to update the head pointer 
		head = curr->next;
	}

	delete curr;
	curr = NULL;
	size--;
}	

