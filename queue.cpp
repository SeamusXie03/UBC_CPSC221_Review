// ------ Singly Linked List implementation with head and tail pointer------
// head is entry, tail is exit
// Time: O(1)
// Space: O(1)
void enqueue(LIT d) {
	Node* newN = new Node(d);
	newN->next = head;
	head = newN;
	size++;
}

// head is entry, tail is exit
// Time: O(n)
// Space: O(1)
LIT dequeue() {
	// save the return Value
	LIT returnVal = tail->data;
	Node* temp = tail;
	// update the tail pointer to its previous value
	tail = findBefore(tail);
	delete temp;
	size--;
	return returnVal;
}

// head is exit, tail is entry
// Time: O(1)
// Space: O(1)
void enqueue(LIT d) {
	Node* newN = new Node(d);
	newN->next = tail->next;
	tail->next = newN; 
	tail = newN;
	size++;
}

// head is exit, tail is entry
// Time: O(1)
// Space: O(1)
LIT dequeue() {
	// save the return Value
	LIT returnVal = head->data;
	Node* temp = head;
	// update the head pointer to its next value
	head = head->next;
	delete temp;
	size--;
	return returnVal;
}

// ------ Array implementation ------
// Time for enqueue and dequeue: O(1)
// Space: O(1)
