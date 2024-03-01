// An integer binary search tree

struct TreeNode 
{                                           
   struct TreeNode *leftPtr; // pointer to left subtree
   int data; // node value                               
   struct TreeNode *rightPtr; // pointer to right subtree
}; // end structure treeNode 
        
typedef struct TreeNode * TreeNodePtr; // synonym for TreeNode*
                    
typedef struct 
{
	int size;
	TreeNodePtr root;
}BST;

// prototypes

void insertNode ( BST *, int );

void insertNode_R (TreeNodePtr * t , int value)
{
  if((*t)==NULL)
  {
   (*t) =(TreeNodePtr) malloc(sizeof(struct TreeNode));
	   if((*t))
      {
         (*t)->leftPtr=NULL;
         (*t)->rightPtr=NULL;
         (*t)->data=value;
      }
  }
  else{
     if((*t)->data>=value) //left
     {
         insertNode_R(&(*t)->leftPtr, value);
     }
        
     else //right
     {
         insertNode_R(&(*t)->rightPtr, value);
     }
      
   }
}

void insertNode( BST *b , int value )
{
	TreeNodePtr t = b->root;
   TreeNodePtr new_node;

	int inserted= 0;

	new_node =(TreeNodePtr) malloc(sizeof(struct TreeNode));

	if(new_node)
   {
		new_node->leftPtr=NULL;
		new_node->rightPtr=NULL;
		new_node->data=value;
   }

	/*First Node*/

	if(!b->root)
   {
      b->root=new_node;
   }
	else {
      while(!inserted)
      {
         if(t->data >= value)
         {
         /* move/insert to the left*/
            if(!t->leftPtr)
            {
               t->leftPtr = new_node;
               inserted = 1;
            }
            else
            {
               t = t->leftPtr;
            }
         }
         else
         {
         /* move/ insert to the right*/
            if(!t->rightPtr)
            {
               t->rightPtr = new_node;
               inserted = 1;
            }
            else
            {
               t = t->rightPtr;
            }
         }
	   }
   }//end while		

  b->size++;
  
}//end function


void inOrder( TreeNodePtr treePtr )
{ 
   // if tree is not empty, then traverse
   if (treePtr) 
   {        
      inOrder( treePtr->leftPtr ); //Recursion to the left
 
      printf("%3d",treePtr->data) ;  //print the value 
   
      inOrder( treePtr->rightPtr ); //Recursion to the right
   }                        
}


void preOrder( TreeNodePtr treePtr)
{
   if (treePtr)
   {
      printf("%3d",treePtr->data);

      preOrder( treePtr->leftPtr );

      preOrder( treePtr->rightPtr );
   }
}

void postOrder( TreeNodePtr treePtr )
{
   if (treePtr)
   {
      postOrder( treePtr->leftPtr );

      postOrder( treePtr->rightPtr );

      printf("%3d",treePtr->data);
   }
   
} 

void print2DUtil(TreeNodePtr treePtr, int space)
{
   if (!treePtr) 
   {
      return;
   }

   space += 5;

   print2DUtil(treePtr->rightPtr, space);

   printf("\n");

   for (int i = 5; i < space; i++)
   {
      printf("  ");
   }

   printf("(%d)\n", treePtr->data);

   print2DUtil(treePtr->leftPtr, space);
}

// Wrapper over print2DUtil()
void print2D(TreeNodePtr treePtr)
{
   print2DUtil(treePtr, 0);
}