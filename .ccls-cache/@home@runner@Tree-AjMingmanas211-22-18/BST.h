#include "node.h"

class BST {
  int size;
  TreeNodePtr rootPtr;

public:
  BST();
  ~BST();
  void kill(TreeNodePtr);
  void insert_node(int);
  void print_all(int = 0);
  void inOrder(TreeNodePtr);
  void preOrder(TreeNodePtr);
  void postOrder(TreeNodePtr);
  void printTree(TreeNodePtr ,int);
  TreeNode* get_root(){return rootPtr;}
};

BST::BST() {
  rootPtr = nullptr;
}

BST::~BST() { 
  cout << "Kill BST" << endl; 
    kill(rootPtr);
}

void BST::insert_node(int value) {
  int inserted = 0;
  TreeNodePtr new_node, t;
  new_node = new TreeNode(value);
  if (new_node) {
    if (!rootPtr) {// if(size==0)
      rootPtr = new_node;
    }
    else{
      t = rootPtr;
      while(!inserted){
        if(value <= t->get_value()){ 
          if(t->move_left())
            t=t->move_left();
          else{
            t->set_left(new_node);
            inserted =1;
          }   
        }
        else{ 
          if(t->move_right())
            t=t->move_right();
          else{
            t->set_right(new_node);
            inserted = 1;
          }
        }
      }
    }
    ++size;
  }
}

void BST::printTree(TreeNodePtr treePtr,int l) {
  if (treePtr) {
    if(treePtr->move_right()){
      printTree(treePtr->move_right(), l+4);
    }
    if(l){
      cout<<setw(l)<<" ";
    }
     if(treePtr->move_right()){
      cout << " /\n" << setw(l) << " ";
    }
    cout<<treePtr->get_value()<<'\n';

    if(treePtr->move_left()){
      cout<<setw(l)<<" "<<"\\\n";
      printTree(treePtr->move_left(), l+4);
    }  
  }
}

void BST::inOrder(TreeNode*r treePtr) {
  if (treePtr) {
    inOrder(treePtr->move_left()); // Recursion to the left
    cout << treePtr->get_value()<<" "; 
    inOrder(treePtr->move_right()); // Recursion to the right
  }
}

void BST::preOrder(TreeNode* treePtr) {
  if(treePtr){
    TreeNodePtr treePtr=rootPtr;
    cout << treePtr->get_value()<<" ";
    preOrder(treePtr->move_left());
    preOrder(treePtr->move_right());
  }
} 

void BST::postOrder(TreeNode* treePtr) {
  if (treePtr) {
    postOrder(treePtr->move_left());
    postOrder(treePtr->move_right());
    cout << treePtr->get_value()<<" ";

  }   
} 

void BST::kill(TreeNode* treePtr) {
  if (treePtr) {
    kill(treePtr->move_left());
    kill(treePtr->move_right());
    delete treePtr;
  }
}



void BST::print_all(int option) {
  switch (option) {
  case 1:
    inOrder(rootPtr);
    cout << endl;
    break;
  case 2:
    preOrder(rootPtr);
    cout << endl;
    break;
  case 3:
    postOrder(rootPtr);
    cout << endl;
    break;
  case 4:
    printTree(rootPtr, 0);
    break;
    cout<<"\n";
  default:
    cout << "inOrder" << endl;
    inOrder(rootPtr);
    cout << endl;
    cout << "preOrder" << endl;
    preOrder(rootPtr);
    cout << endl;
    cout << "postOrder" << endl;
    postOrder(rootPtr);
    cout << endl;
    cout << "Tree" << endl;
    printTree(rootPtr,0);
    cout << endl;
  }
}
