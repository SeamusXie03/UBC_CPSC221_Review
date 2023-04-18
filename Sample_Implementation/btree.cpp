
struct Node {
    int numkeys;
    int key[MAX_KEYS];
    Node* child[MAX_CHILDREN];
    bool leaf;
};


bool B-Tree-Search(Node & x, T key){
  int i=0;
  
  //find which child to proceed
  while (i<x.numkeys && key > x.key[i]){
    i++;
  }
  if(i<x.numkeys && key == x.key[i]){
      return true;
  }
  if(x.leaf == true){
    return false;
  }
  //??不理解
  else{
    Node b = DISK-READ(x.child[i]);
    return B-Tree-Search(b,key);
  }
}
