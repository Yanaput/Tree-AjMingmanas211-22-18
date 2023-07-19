class TreeNode {      
private :
   TreeNode *leftPtr; // pointer to left subtree 
   int data; // node value                               
   TreeNode *rightPtr; // pointer to right subtree
public:
        TreeNode(int); 
        ~TreeNode();
        void set_left(TreeNode* t);
        void set_right(TreeNode* t){rightPtr=t;}
        int get_value(){return data;}
        TreeNode* move_right(){ return rightPtr; }
        TreeNode* move_left(){ return leftPtr; }
}; // end structure treeNode 
        

typedef TreeNode * TreeNodePtr; 
TreeNode::TreeNode(int x){
   data =x;
   leftPtr=NULL;
   rightPtr=NULL;
}

void TreeNode::set_left(TreeNode *t){
  leftPtr=t;
}

TreeNode::~TreeNode(){
  cout<<"Deleting "<< data<<endl;
}
