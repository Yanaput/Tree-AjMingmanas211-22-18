
#include <iostream>
#include <iomanip>
using namespace std;
#include "BST.h"
int main(int argc, char **argv) {
  unsigned int i; // counter to loop from 1-10
  BST b;
  for (i = 1; i < argc; ++i) {
       b.insert_node (atoi(argv[i]));
  }
  cout<<"1.inorder 2.preorder 3. postorder 4.tree\n";
  int choice;
  cout <<": ";
  cin>>choice;
  switch(choice){
    case 1 : 
      cout<<"inorder\n";
      break;
    case 2 : 
      cout<<"preorder\n";
      break;
    case 3 :
      cout<<"postorder\n";
      break;
    case 4 :
      cout<<"tree \n";
      break;
    default:
      cout<<"inorder\n";
      break;
  }
  b.print_all(choice);
  
  
  
} // end main
