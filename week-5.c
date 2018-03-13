
#include <stdio.h>
#include<stdlib.h>


struct TreeNode
{	
    int value;
    struct TreeNode* left;
    struct TreeNode* right;


};

struct TreeNode* newNode(int data)
{
    struct TreeNode* node = (struct TreeNode*)
                             malloc(sizeof(struct TreeNode));
    node->value  = data;
    node->left  = NULL;
    node->right = NULL;
 
    return(node);
};

struct TreeNode *root1=NULL;
struct TreeNode *root2=NULL;
int flag=0;  //// to keep a track if not a single subtree of 1st tree matches with 2nd tree 


int Is_Same(struct TreeNode* root1, struct TreeNode* root2) ///// check if 2 trees are identical or not
{
    /* both empty */
    if (root1==NULL && root2==NULL)
        return 1;
 
    /* both non-empty */
    if (root1!=NULL && root2!=NULL)
    {
        
	if (root1->value == root2->value)
        {
            if( Is_Same(root1->left, root2->left) && Is_Same(root1->right, root2->right))
		return 1;
        }
	else return 0;

    }
     
    /*  one empty, one not  */
    return 0;
} 


///// inorder traversing of 1st tree to check if 2nd tree matches the subtree of 1st tree with the current node as the root of the subtree 

void check_inorder(struct TreeNode * tree)
{
    if (tree)
    {
        check_inorder(tree->left);
	
	if(Is_Same(tree, root2))
        {	printf("Both trees are identical at node %d of 1st tree",tree->value);
		flag=1;
	}
   		
	check_inorder(tree->right);
    }
}


struct TreeNode* insert(struct TreeNode* node, int value) ///// insertion of an element in a binary tree. I have used the method of insertion used in Binary Search Tree. We can use other methods also.
{
    
    if (node == NULL) return newNode(value);
    
    if (value < node->value)
        node->left  = insert(node->left, value);

    else if (value > node->value)
        node->right = insert(node->right, value);   
 
    
    return node;
}


int main()
{
	
    root1 = newNode(1); //// root of 1st tree
        
    insert(root1,2);
    insert(root1,3);
    insert(root1,4);
    insert(root1,5);

    /* Tree 1 

	     1
	   2   3 
		       4 
		         5

    */
    
    root2 = newNode(1); //// root of 2nd tree
    insert(root2,4);
    insert(root2,5);
    
    /*   
    
    Tree 2

      1
	      4
	        5
    */ 

    if(root1 && root2)
    {check_inorder(root1);}

    else 
     { printf("Error. Trees cannot be empty or Null");
       return 0;
     }

    if (flag==0)
     {printf("\n No subtree of 1st tree matches with 2nd tree \n");
     }	

    return 0;

}



