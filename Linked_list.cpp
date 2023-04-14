
// Time: O(1)
// Space: O(1)
void insertAtFront(Node*& curr, LIT e) {
	curr = new Node(e, curr);
}

// Time: O(n)
// Space: O(n)
void printReverse(Node* curr) {
	if (curr != NULL) {
		// go all the way to the bottom, then start printing
		printReverse(curr->next);
		cout << curr->data << end;
	}
}

// Time: O(n)
// Space: O(n)
void printReverseOdds(Node* curr) {
	if (curr == NULL) {
		// if there is no item in the list, return
		return;
	} else if (curr->next == NULL) {
		// if there is only one item in the list, print and return
		cout << curr->data << end;
	} else { 
		// if there is more than one item in the list, 
		// go to the next layer and then come back to print
		printReverseOdds(curr);
		cout << curr->data << end;
	}
}

// Time: O(n)
// Space: O(n)
Node* reverse(Node* curr) {
	if (curr != NULL && curr->next != NULL) {
		// get the revRest head pointer
		Node* revRest = reverse(curr->next);
		curr->next->next = curr;
		curr->next = NULL;

		// return the head of the reversed list
		curr = revRest;
	}
	return curr;
}
