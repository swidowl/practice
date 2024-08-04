/******************************************************************************

Recursive BST function using double pointer and void function.

*******************************************************************************/
#include <iostream>
using namespace std;
typedef struct node{
    int data;
    node *left;
    node *right;
} node;

class bst{
        public:
        void insert(node **root, int data)
        {
           // cout<<"here""data"<<data<<endl;
            
            if(*root == NULL)
            {
                node *temp = new node;
                 temp->data = data;
                temp->left = temp->right = NULL;
                *root = temp;
                
                return ;
            }
           
            if((*root)->data < data)
            {
                
               insert(&(*root)->left, data );
                //cout<<"left"<<temp->data<<endl;
            }
            else{
               insert(&(*root)->right, data);
               
               // cout<<"right"<<temp->data<<endl;
            }
            return ;
        }
        void display(node *root)
        {
            if(root==NULL)
            return;
            
            display(root->left);
            cout<<root->data;
            display(root->right);
        }
      
};
int main()
{
    bst obj ;
    node *root = new node;
    
     obj.insert(&root, 10);
    
     obj.insert(&root, 20);
    
     obj.insert(&root, 30);
   
     obj.display(root);

    return 0;
}
