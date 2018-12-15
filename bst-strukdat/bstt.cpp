// C program to demonstrate insert operation in binary search tree
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
  
struct book
{
    int id;
	char name[100];
    struct book *left, *right;
};
  
// A utility function to create a new BST node
struct book *newBook(int item, char name[])
{
    struct book *temp =  (struct book *)malloc(sizeof(struct book));
    temp->id = item;
	strcpy(temp->name, name);
    temp->left = temp->right = NULL;
    return temp;
}
  
// A utility function to do inorder traversal of BST
void inorder(struct book *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \n", root->id);
		printf("%s \n", root->name);
        inorder(root->right);
    }
}
  
/* A utility function to insert a new node with given key in BST */
struct book* insert(struct book* book, int id, char name[])
{
    /* If the tree is empty, return a new node */
    if (book == NULL) return newBook(id, name);
 
    /* Otherwise, recur down the tree */
    if (id < book->id)
        book->left  = insert(book->left, id, name);
    else if (id > book->id)
        book->right = insert(book->right, id, name);   
 
    /* return the (unchanged) node pointer */
    return book;
}
  
struct book* search(struct book* root, int id)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->id == id){
		printf("Data found");
       return root;
	}
	else{
		printf("Data not found");
	}
    
    // Key is greater than root's key
    if (root->id < id){
       return search(root->right, id);
	}
 
    // Key is smaller than root's key
    return search(root->left, id);
}

// Driver Program to test above functions
int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    struct book *root = NULL;
    root = insert(root, 50, "a");
    insert(root, 30, "b");
    insert(root, 20, "adad");
    insert(root, 40, "asd");
    insert(root, 70, "erg");
    insert(root, 60, "acasc");
    insert(root, 80, "werc");
	search(root, 15);
    // print inoder traversal of the BST
    inorder(root);
  
	getchar();
    return 0;
}

