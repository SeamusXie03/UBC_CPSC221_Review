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

// ------ Using two stacks ------
public class Queue<E>
{
    private Stack<E> inbox = new Stack<E>();
    private Stack<E> outbox = new Stack<E>();

    // always push to the inbox
    // Time: O(1)
    public void queue(E item) {
        inbox.push(item);
    }

    // always pop from teh outbox
    // Time: average O(1) per operation
    public E dequeue() {
    	// when the outbox is empty, refill
	// O(n) for an operation
        if (outbox.isEmpty()) {
            while (!inbox.isEmpty()) {
               outbox.push(inbox.pop());
            }
        }
	// however, on average of n operation, this function will be constant
        return outbox.pop();
    }
}
