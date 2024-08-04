/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

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
           
            if((*root)->data > data)
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
// this delete gives correct result if element is found , even though logic is not correct check and understand what is happening
        void del(node **root, int data)
        {
            node *temp = *root;
          //  cout<<"del"<<temp->data<<" " <<data<<endl;
         
          
            if(temp->data == data)
            {
                cout<<"del"<<temp->data;
                if(temp->left)
                *root = temp->left;
                else
                *root = temp->right;
                
                cout<<"del"<<temp->data;
                temp->left = temp->right = NULL;
                delete temp;
                return;
            }
            else if(temp->data > data)
            {
                del(&temp->left,data);
            }
            else if(temp->data < data)
            {
                del(&temp->right,data);
            }
            else
            {
                cout<<"no node found"<<endl;
            }
          
        }
        void display(node *root)
        {
            if(root==NULL)
            return;
            
            display(root->left);
            cout<<root->data<<" ";
            display(root->right);
        }
      
};
int main()
{
    bst obj ;
    node *root = NULL;
    
      obj.insert(&root, 1);
    
     obj.insert(&root, 3) ;
     obj.insert(&root, 5);
    
     obj.insert(&root, 7);
    
     obj.insert(&root, 8);
      obj.insert(&root, 9);
       obj.insert(&root, 11);
       obj.insert(&root, 12);
       obj.insert(&root, 13);
       obj.insert(&root, 14);
       obj.insert(&root, 15);
       obj.insert(&root, 17);
       obj.insert(&root, 18);
       obj.insert(&root, 20);
    
     
    obj.del(&root, 50);
   
     obj.display(root);

    return 0;
}
