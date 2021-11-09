/*
 - Implementation of a binary tree object and its traversal.
 - functions containing an underscore, ie. _h
   denote helper functions which handle most of the
   actual work. The function with the same name,
   but without _h, are functions which call the
   helper functions.
*/

#include<iostream>
#include<vector>

using namespace std;

struct Node {
       int data;
       Node *left;
       Node *right;
};

class BSTree {
      private:
        Node *root;
        void insert_h(int,  Node * );
        void preorder_h(Node *);
        void inorder_h(Node *);
        void postorder_h(Node *);
      public:
        void insert(int);
        void generateBST(vector<int>);
        void preorderTraverse();
        void inorderTraverse();
        void postorderTraverse();

      BSTree() {
         root = NULL;
      }
};


/*Node Insertion Functions*/
void BSTree::insert_h(int value, Node *leaf) {
           if(value <= leaf->data) {
              if(leaf->left != NULL)
                insert_h(value, leaf->left);
              else {
                leaf->left = new Node;
                leaf->left->data = value;
                leaf->left->left = NULL;    
                leaf->left->right = NULL;   
              }  
           }
           else if(value > leaf->data) {
                if(leaf->right != NULL)
                   insert_h(value, leaf->right);
                else {
                   leaf->right = new Node;
                   leaf->right->data = value;
                   leaf->right->left = NULL;  
                   leaf->right->right= NULL;
                 }
              }
      }

void BSTree::insert(int value){
           if(root != NULL)
              insert_h(value, root);
           else {
              root = new Node;
              root->data = value;
              root->left = NULL;
              root->right = NULL;
           }
      }

void BSTree::generateBST(vector<int> v){
           for (auto x = v.begin(); x != v.end(); ++ x)
                insert(*x); // placing elements of the vector into the BSTree
      }

void BSTree::preorder_h(Node *current) {
             if (current != NULL) {
               cout<< current->data << endl;
               preorder_h(current->left);
               preorder_h(current->right);
             }
      }
void BSTree::preorderTraverse(){
     preorder_h(root);
}

void BSTree::inorder_h(Node *current) {
             if (current != NULL) {
               inorder_h(current->left);
               cout<< current->data << endl;
               inorder_h(current->right);
             }
      }
void BSTree::inorderTraverse(){
     inorder_h(root);
}

void BSTree::postorder_h(Node *current) {
             if (current != NULL) {
               postorder_h(current->left);
               postorder_h(current->right);
               cout<< current->data << endl;
             }
      }
void BSTree::postorderTraverse(){
     postorder_h(root);
}


int main(){
    vector<int> v = {3,6,2,8,1,2,9,7};
    BSTree T;
    T.generateBST(v);
    cout << "---------" << endl;
    T.preorderTraverse();
    cout << "---------" << endl;
    T.inorderTraverse();
    cout << "---------" << endl;
    T.postorderTraverse();
    return 0;
}

/*
BSTree for v = {3,6,2,8,1,2,9,7}
          (3)
         /   \
       (2)    (6)
      /  \    /  \
    (1)  (N) (N) (8)
    / \        /   \
   (N)(2)    (7)   (9)
      / \    / \   / \
    (N) (N)(N) (N)(N) (N)
N = NULL
*/
