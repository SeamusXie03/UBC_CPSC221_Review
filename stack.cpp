// ------ Linked List implementation ------
// Time: O(1)
// Space: O(1)
void push(LIT d) {
	Node* newN = new Node(d);
	newN->next = top;
	top = newN;
	size++;
}

// Time: O(1)
// Space: O(1)
LIT pop() {
	// save the return Value
	LIT returnVal = top->data;
	Node* t = top;
	// update top to the second last node
	top = t->next;
	// free the object on the heap
	delete t;
	// update the size of the stack
	size--;
	return returnVal;
}


// ------ Array implementation ------
// We are only modifing the right side of the vector
// Time: O(1)
// Space: O(1)
void push(LIT d) {
	items.push_back(d);
}

// Time: O(1) per push if we scale up by c every time
// Space: O(1)
LIT pop() {
	// peek for the return value
	LIT returnVal = items[items.size - 1];
	// pop the last one out
	items.pop_back();
	return returnVal;
}

