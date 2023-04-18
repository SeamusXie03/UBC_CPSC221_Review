// Worst Time: O(h)
template <class K, class V>
V AVLTree<K, V>::find(const K& key) const {
    return find(root, key);
}

template <class K, class V>
V AVLTree<K, V>::find(Node* subtree, const K& key) const {
    if (subtree == NULL)
        return V();
    else if (key == subtree->key)
        return subtree->valu ;
    else {
        if (key < subtree->key)
            return find(subtree->left, key);
        else
            return find(subtree->right, key);
    }
}

// Worst Time: O(h)
template <class K, class V>
void AVLTree<K, V>::insert(const K & key, const V & value) {
    insert(root, key, value);
}

template <class K, class V>
void AVLTree<K, V>::insert(Node*& subtree, const K& key, const V& value) {
    if (subtree == NULL)
        subtree = new Node(key, value);
    else {
        if (key < subtree->key) {
            insert(subtree->left, key, value);
        } else {
            insert(subtree->right, key, value);
        }
    }

    // Rebalance tree after insertion (don't remove this)
    rebalance(subtree);
}

template <class K, class V>
void AVLTree<K, V>::updateHeight(Node* node) {
	node->height = max(height(node->left), height(node->right)) + 1;
}

// Time: O(1)
template <class K, class V>
void AVLTree<K, V>::rotateLeft(Node*& t) {
    *_out << __func__ << endl; // Outputs the rotation name (don't remove this)

    Node* newSubRoot = t->right;
    t->right = newSubRoot->left;
    newSubRoot->left = t;
    t = newSubRoot;

    // update the heights for t->left and t (in that order)
    updateHeight(t->left);
    updateHeight(t);
}

// Time: O(1)
template <class K, class V>
void AVLTree<K, V>::rotateRight(Node*& t) {
    *_out << __func__ << endl; // Outputs the rotation name (don't remove this)

    Node* newSubRoot = t->left;
    t->left = newSubRoot->right;
    newSubRoot->right = t;
    t = newSubRoot;

    // updates heights
    updateHeight(t->right);
    updateHeight(t);
}

// Time: O(1)
template <class K, class V>
void AVLTree<K, V>::rotateLeftRight(Node*& t) {
    *_out << __func__ << endl; // Outputs the rotation name (don't remove this)

    rotateLeft(t->left);
    rotateRight(t);
}

// Time: O(1)
template <class K, class V>
void AVLTree<K, V>::rotateRightLeft(Node*& t) {
    *_out << __func__ << endl; // Outputs the rotation name (don't remove this)

	rotateRight(t->right);
	rotateLeft(t);
}

template <class K, class V>
void AVLTree<K, V>::rebalance(Node*& subtree) {
    // positive values mean left is "heavier", negative means right is "heavier"
    int balance = height(subtree->left) - height(subtree->right); // checks which side is "heavier"

    if (balance > 1) { // if left side larger than right
        if (height(subtree->left->left) >= height(subtree->left->right)) {
            rotateRight(subtree);
        } else {
            rotateLeftRight(subtree);
        }
    } else if (balance < -1) { // if right side larger than left
        if (height (subtree->right->right) >= height(subtree->right->left)) {
            rotateLeft(subtree);
        } else {
            rotateRightLeft(subtree);
        }
    } else {
        updateHeight(subtree); // if balanced 
    }
}

template <class K, class V>
void AVLTree<K, V>::remove(const K& key) {
    remove(root, key);
}

template <class K, class V>
void AVLTree<K, V>::remove(Node*& subtree, const K& key) {
    if (subtree == NULL)
        return;

    if (key < subtree->key) {
        remove(subtree->left, key);
        rebalance(subtree);
    } else if (key > subtree->key) {
        remove(subtree->right, key);
        rebalance(subtree);
    } else {
        /* Reached the node that we need to delete */
        if (subtree->left == NULL && subtree->right == NULL) {
            /* Case 1: Node to remove has no children */
            delete subtree;
            subtree = NULL;
            return;
        } else if (subtree->left != NULL && subtree->right != NULL) {
            Node * pred = subtree->left;
            while (pred->right) {
                pred = pred->right;
            }

            swap(subtree, pred);
            remove(subtree->left, key);

        } else {
            /* Case 3: Node to remove has one child */
            Node* curr = subtree;
            subtree = max(subtree->left, subtree->right);
            delete curr;
        }
        rebalance(subtree);
    }
}

template <class K, class V>
void AVLTree<K, V>::swap(Node*& first, Node*& second){
    K tempkey = first->key;
    V tempvalue = first->value;
    first->key = second->key;
    first->value = second->value;
    second->key = tempkey;
    second->value = tempvalue;
}
